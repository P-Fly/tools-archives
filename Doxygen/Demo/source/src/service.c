/**
 * @file source/src/service.c
 * @brief Definition the service.
 * @author Peter.Peng <27144363@qq.com>
 * @date 2022
 *
 * Embedded Device Software
 * Copyright (C) 2022 Peter.Peng
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include "cmsis_os.h"
#include "framework.h"

/**
 * @defgroup Service_API Service API
 *
 * @brief Service Control API
 *
 * @{
 */

/**
 * @defgroup Service_Control Service Control
 *
 * @brief Send the message.
 *
 * @ingroup Service_API
 */

/**
 * @defgroup Service_Property Service Property
 *
 * @brief Get the property.
 *
 * @ingroup Service_API
 */

/**
 * @}
 */

/**
 * @brief   Service routine thread, processing message loops.
 *
 * @param   argument Pointer to the service object handle.
 */
static void service_routine_thread(void* argument)
{
    object* obj = (object*)argument;
    service_t* svc = (service_t*)obj->object_data;
    service_intf_t* intf = (service_intf_t*)obj->object_intf;
    message_t message;
    osStatus_t stat;

    while (1)
    {
        stat = osMessageQueueGet(svc->queue_id,
                                 &message,
                                 NULL,
                                 osWaitForever);
        if (stat != osOK)
        {
            continue;
        }

        if (intf->message_handler)
        {
            intf->message_handler(obj, &message);
        }
    }
}

/**
 * @brief   Initialize the service instance.
 *
 * @param   obj Pointer to the service object handle.
 * @param   config Pointer to the configuration space.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
static int32_t service_init(const object*                   obj,
                            const service_config_t* const   config)
{
    service_t* svc = (service_t*)obj->object_data;
    int32_t ret;

    svc->queue_id = osMessageQueueNew(config->msg_count,
                                      sizeof(message_t),
                                      &config->queue_attr);
    if (!svc->queue_id)
    {
        pr_error("Service <%s> create message queue <%s> failed.",
                 obj->name,
                 config->queue_attr.name);
        return -EINVAL;
    }

    svc->thread_id = osThreadNew(service_routine_thread,
                                 (void*)obj,
                                 &config->thread_attr);
    if (!svc->thread_id)
    {
        pr_error("Service <%s> create thread <%s> failed.",
                 obj->name,
                 config->thread_attr.name);
        return -EINVAL;
    }

    if (svc->init)
    {
        ret = svc->init(obj);
        if (ret)
        {
            return ret;
        }
    }

    return 0;
}

/**
 * @brief   Deinitialize the service instance.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
static int32_t service_deinit(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;
    osStatus_t stat;

    if (svc->deinit)
    {
        svc->deinit(obj);
    }

    if (svc->thread_id)
    {
        stat = osThreadTerminate(svc->thread_id);
        if (stat != osOK)
        {
            pr_error("Service <%s> terminate thread <%s> failed, stat %d.",
                     obj->name,
                     osThreadGetName(svc->thread_id),
                     stat);
        }
    }

    if (svc->queue_id)
    {
        stat = osMessageQueueDelete(svc->queue_id);
        if (stat != osOK)
        {
            pr_error("Service <%s> delete message queue failed, stat %d.",
                     obj->name,
                     stat);
        }
    }

    return 0;
}

/**
 * @brief   Handle service message queue.
 *
 * @param   obj Pointer to the service object handle.
 * @param   message Pointer to the service message structure.
 */
static void service_message_handler(const object*           obj,
                                    const message_t* const  message)
{
    service_t* svc = (service_t*)obj->object_data;

    if (svc->message_handler)
    {
        svc->message_handler(obj, message);
    }
}

/**
 * @brief   Generic service interface.
 */
const service_intf_t service_intf =
{
    .init               = service_init,
    .deinit             = service_deinit,
    .message_handler    = service_message_handler,
};

/**
 * @brief   Probe the service object.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
int32_t service_probe(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;
    const service_config_t* config =
        (const service_config_t*)obj->object_config;
    service_intf_t* intf = (service_intf_t*)obj->object_intf;
    int32_t ret;

    svc->owner = obj;

    if (intf->init)
    {
        ret = intf->init(obj, config);
        if (ret)
        {
            return ret;
        }
    }

    pr_info("Object <%s> probe succeed.", obj->name);

    return 0;
}

/**
 * @brief   Remove the service object.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
int32_t service_shutdown(const object* obj)
{
    service_intf_t* intf = (service_intf_t*)obj->object_intf;
    int32_t ret;

    if (intf->deinit)
    {
        ret = intf->deinit(obj);
        if (ret)
        {
            return ret;
        }
    }

    pr_info("Object <%s> shutdown succeed.", obj->name);

    return 0;
}

/**
 * @brief   Get the thread ID for service.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns the thread ID.
 *
 * @ingroup Service_Property
 */
osThreadId_t service_get_thread_id(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;

    return svc->thread_id;
}

/**
 * @brief   Get the queue ID for service.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns the queue ID.
 *
 * @ingroup Service_Property
 */
osMessageQueueId_t service_get_queue_id(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;

    return svc->queue_id;
}

/**
 * @brief   Get the private data for service.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns the private data.
 *
 * @ingroup Service_Property
 */
void* service_get_priv_data(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;

    return svc->priv;
}

/**
 * @brief   Get the service handle.
 *
 * @param   obj Pointer to the service object handle.
 *
 * @retval  Returns the service handle.
 *
 * @ingroup Service_Property
 */
service_t* service_get_svc(const object* obj)
{
    service_t* svc = (service_t*)obj->object_data;

    return svc;
}

/**
 * @brief   Broadcast event messages to all services.
 *
 * @param   message Message structure to send.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 *
 * @ingroup Service_Control
 */
int32_t service_broadcast_message(const message_t* message)
{
    extern service_t module_service$$Base[];
    extern service_t module_service$$Limit[];

    const service_t* start = module_service$$Base;
    const service_t* end = module_service$$Limit;
    const service_t* svc;
    osStatus_t stat;
    uint32_t timeout;
    BaseType_t is_irq = xPortIsInsideInterrupt();

    if (!message)
    {
        return -EINVAL;
    }

    if (is_irq)
    {
        timeout = 0;
    }
    else
    {
        timeout = CONFIG_MSG_SEND_BLOCK_TIMEOUT_MS * osKernelGetTickFreq() /
                  1000;
    }

    for (svc = start; svc < end; svc++)
    {
        if (svc)
        {
            stat = osMessageQueuePut(svc->queue_id, message, 0, timeout);
            if (stat != osOK)
            {
                pr_error("Broadcast %s(0x%x) failed, stat %d.",
                         msg_id_to_str(message->id),
                         message->id,
                         stat);

                return -EPIPE;
            }
        }
    }

    pr_info("Broadcast %s(0x%x) succeed, 0x%x, 0x%x, 0x%x, 0x%x.",
            msg_id_to_str(message->id),
            message->id,
            message->param0,
            message->param1,
            message->param2,
            message->param3);

    return 0;
}

/**
 * @brief   Unicast event messages to a specified service.
 *
 * @param   svc Pointer to the service handle.
 * @param   message Message structure to send.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 *
 * @ingroup Service_Control
 */
int32_t service_unicast_message(const service_t* svc, const message_t* message)
{
    osStatus_t stat;
    uint32_t timeout;
    BaseType_t is_irq = xPortIsInsideInterrupt();

    if (!svc)
    {
        return -EINVAL;
    }

    if (!message)
    {
        return -EINVAL;
    }

    if (is_irq)
    {
        timeout = 0;
    }
    else
    {
        timeout = CONFIG_MSG_SEND_BLOCK_TIMEOUT_MS * osKernelGetTickFreq() /
                  1000;
    }

    stat = osMessageQueuePut(svc->queue_id, message, 0, timeout);
    if (stat != osOK)
    {
        pr_error("Unicast %s(0x%x) failed, stat %d.",
                 msg_id_to_str(message->id),
                 message->id,
                 stat);

        return -EPIPE;
    }

    pr_info("Unicast %s(0x%x) succeed, 0x%x, 0x%x, 0x%x, 0x%x.",
            msg_id_to_str(message->id),
            message->id,
            message->param0,
            message->param1,
            message->param2,
            message->param3);

    return 0;
}
