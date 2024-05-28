/**
 * @file include/table_demo.h
 * @brief Definition the demo for table.
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

#ifndef __TABLE_DEMO_H__
#define __TABLE_DEMO_H__

/**
 * @addtogroup Demos Demos
 *
 * @brief Some small demos.
 *
 * @{
 */

/**
 * @defgroup Table_Demo Table
 *
 * @brief The demo for table.
 *
 * @ingroup Demos
 */

/**
 * @}
 */

/**
 * @brief   Table Demo 1.
 *
 * <table>
 * <caption id="multi_row">Complex table</caption>
 * <tr><th>Column 1 <th>Column 2 <th>Column 3
 * <tr><td rowspan="2">cell row=1+2,col=1<td>cell row=1,col=2<td>cell row=1,col=3
 * <tr><td rowspan="2">cell row=2+3,col=2 <td>cell row=2,col=3
 * <tr><td>cell row=3,col=1 <td rowspan="2">cell row=3+4,col=3
 * <tr><td colspan="2">cell row=4,col=1+2
 * <tr><td>cell row=5,col=1 <td colspan="2">cell row=5,col=2+3
 * <tr><td colspan="2" rowspan="2">cell row=6+7,col=1+2 <td>cell row=6,col=3
 * <tr> <td>cell row=7,col=3
 * <tr><td>cell row=8,col=1 <td>cell row=8,col=2\n
 * <table>
 * <tr><td>Inner cell row=1,col=1<td>Inner cell row=1,col=2
 * <tr><td>Inner cell row=2,col=1<td>Inner cell row=2,col=2
 * </table>
 * <td>cell row=8,col=3
 * <ul>
 * <li>Item 1
 * <li>Item 2
 * </ul>
 * </table>
 *
 * For easiest table please refer to @ref table_demo_2.
 *
 * @ingroup Table_Demo
 */
void table_demo_1(void);

/**
 * @brief   Table Demo 2.
 *
 * Table 1:
 * First Header | Second Header
 * ------------ | -------------
 * Content Cell | Content Cell
 * Content Cell | Content Cell
 *
 * Table 2:
 * | Right | Center | Left |
 * | ----: | :----: | :---- |
 * | 10 | 10 | 10 |
 * | 1000 | 1000 | 1000 |
 *
 * Table 3:
 * | Right | Center | Left |
 * | ----: | :----: | :---- |
 * | 10 | 10 | 10 |
 * | ^ | 1000 | 1000 |
 *
 * Table 4:
 * | Right | Center | Left |
 * | ----: | :----: | :---- |
 * | 10 | 10 | 10 |
 * | 1000 |||
 *
 * For complex table please refer to @ref multi_row.
 *
 * @ingroup Table_Demo
 */
void table_demo_2(void);

#endif /* __TABLE_DEMO_H__ */
