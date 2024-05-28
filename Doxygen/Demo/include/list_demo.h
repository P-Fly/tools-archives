/**
 * @file include/list_demo.h
 * @brief Definition the demo for list.
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

#ifndef __LIST_DEMO_H__
#define __LIST_DEMO_H__

/**
 * @addtogroup Demos Demos
 *
 * @brief Some small demos.
 *
 * @{
 */

/**
 * @defgroup List_Demo List
 *
 * @brief The demo for list.
 *
 * @ingroup Demos
 */

/**
 * @}
 */

/**
 * @brief   Lists Demo.
 *
 *    A list of events:
 *        - mouse events
 *            -# mouse move event
 *            -# mouse click event\n
 *               More info about the click event.
 *            -# mouse double click event
 *        - keyboard events
 *            1. key down event
 *            2. key up event
 *        - checkbox list
 *            - [ ] unchecked
 *            - [x] checked
 *
 *    More text here.
 *
 * @ingroup List_Demo
 */
void list_demo(void);

#endif /* __LIST_DEMO_H__ */
