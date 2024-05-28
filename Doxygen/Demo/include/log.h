/**
 * @file include/log.h
 * @brief Generic log interface.
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

#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>

#define RED_LABEL    "\033[47;31m"  /**< Define the text color as red as the Console output. */
#define NORMAL_LABEL "\033[0m"      /**< Recover the Console output to normal color. */

/**
 * Log an error message.
 */
#define pr_error(format, ...) dbg_cli_output( \
        RED_LABEL "[E][%d][%s][%d] " format "\r\n" NORMAL_LABEL, \
        dbg_cli_get_tick(), \
        __FUNCTION__, \
        __LINE__, \
        ## __VA_ARGS__)

/**
 * Log a warning message.
 */
#define pr_warning(format, ...) dbg_cli_output( \
        RED_LABEL "[W][%d][%s][%d] " format "\r\n" NORMAL_LABEL, \
        dbg_cli_get_tick(), \
        __FUNCTION__, \
        __LINE__, \
        ## __VA_ARGS__)

/**
 * Log an info message.
 */
#define pr_info(format, ...) dbg_cli_output( \
        "[I][%d][%s][%d] " format "\r\n", \
        dbg_cli_get_tick(), \
        __FUNCTION__, \
        __LINE__, \
        ## __VA_ARGS__)

/**
 * Log a debug message.
 */
#define pr_debug(format, ...) dbg_cli_output( \
        "[D][%d][%s][%d] " format "\r\n", \
        dbg_cli_get_tick(), \
        __FUNCTION__, \
        __LINE__, \
        ## __VA_ARGS__)

/**
 * No message to print.
 */
#define pr_no_mesg(...)

#endif /* __LOG_H__ */
