/**
 * @file include/message.h
 * @brief Definition the message.
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

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief   Message structure definition.
 */
typedef struct
{
    uint32_t    id;         /**< Message identifier */

    uint32_t    param0;     /**< Message param 0 */
    uint32_t    param1;     /**< Message param 1 */
    uint32_t    param2;     /**< Message param 2 */
    uint32_t    param3;     /**< Message param 3 */
} __attribute__((packed)) message_t;

#ifndef DOC_HIDDEN
/* Notes: These macros are used internally, and we need to hide it in the document. */
/* System type message */
#define MSG_ID_SYS_BASE     0x00000100
/* LED type message */
#define MSG_ID_LED_BASE     0x00000200
/* Button type message */
#define MSG_ID_BTN_BASE     0x00000300
/* BLE type message */
#define MSG_ID_BLE_BASE     0x00000400
/* Man-machine type message */
#define MSG_ID_MMI_BASE     0x00000500
#endif

/**
 * @brief           Notify system startup is completed.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_SYS_STARTUP_COMPLETED
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_SYS_STARTUP_COMPLETED (MSG_ID_SYS_BASE | 0x01)

/**
 * @brief           Run automatic test.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_SYS_RUN_AUTOMATIC_TEST
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_SYS_RUN_AUTOMATIC_TEST (MSG_ID_SYS_BASE | 0x02)

/**
 * @brief           Set LED type.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_LED_SETUP
 *  message.param0  led_id_e.
 *  message.param1  led_type_e.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_LED_SETUP (MSG_ID_LED_BASE | 0x01)

/**
 * @brief           Notify button state.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_BTN_STATE_NOTIFY
 *  message.param0  button_id_e.
 *  message.param1  button_state_e.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_BTN_STATE_NOTIFY (MSG_ID_BTN_BASE | 0x01)

/**
 * @brief           Notify BLE SHCI ready.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_BLE_SHCI_READY
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_BLE_SHCI_READY (MSG_ID_BLE_BASE | 0x01)

/**
 * @brief           Notify BLE ADV timeout.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_BLE_ADV_TIMEOUT
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_BLE_ADV_TIMEOUT (MSG_ID_BLE_BASE | 0x02)

/**
 * @brief           Notify BLE HCI connected.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_BLE_HCI_CONNECTED
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_BLE_HCI_CONNECTED (MSG_ID_BLE_BASE | 0x03)

/**
 * @brief           Notify BLE HCI disconnected.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_BLE_HCI_DISCONNECTED
 *  message.param0  None.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_BLE_HCI_DISCONNECTED (MSG_ID_BLE_BASE | 0x04)

/**
 * @brief           Notify client input is completed.
 *
 * Example:
 * @code
 *  message.id      MSG_ID_MMI_CLIENT_INPUT_NOTIFY
 *  message.param0  mmi_cli_type_e.
 *  message.param1  None.
 *  message.param2  None.
 *  message.param3  None.
 * @endcode
 */
#define MSG_ID_MMI_CLIENT_INPUT_NOTIFY (MSG_ID_MMI_BASE | 0x01)

extern const char* msg_id_to_str(uint32_t id);
extern int32_t msg_sys_startup_completed(void);

#endif /* __MESSAGE_H__ */
