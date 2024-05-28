/**
 * @file include/formula_demo.h
 * @brief Definition the demo for formula.
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

#ifndef __FORMULA_DEMO_H__
#define __FORMULA_DEMO_H__

/**
 * @addtogroup Demos Demos
 *
 * @brief Some small demos.
 *
 * @{
 */

/**
 * @defgroup Tormula_Demo Tormula
 *
 * @brief The demo for formula.
 *
 * @ingroup Demos
 */

/**
 * @}
 */

/**
 * @brief   Formula Demo 1.
 *
 * The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
 *
 * \f[
 *  |I_2|=\left| \int_{0}^T \psi(t)
 *          \left\{
 *              u(a,t)-
 *              \int_{\gamma(t)}^a
 *              \frac{d\theta}{k(\theta,t)}
 *              \int_{a}^\theta c(\xi)u_t(\xi,t)\,d\xi
 *              \right\} dt
 *          \right|
 * \f]
 *
 * \f{eqnarray*}{
 *      g &=& \frac{Gm_2}{r^2} \\
 *        &=& \frac{(6.673 \times 10^{-11}\,\mbox{m}^3\,\mbox{kg}^{-1}\,
 *            \mbox{s}^{-2})(5.9736 \times 10^{24}\,\mbox{kg})}{(6371.01\,\mbox{km})^2} \\
 *        &=& 9.82066032\,\mbox{m/s}^2
 * \f}
 *
 * @ingroup Tormula_Demo
 */
void formula_demo_1(void);

#endif /* __FORMULA_DEMO_H__ */
