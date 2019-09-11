/*----------------------------------------------------------------------------
 * Copyright (c) <2013-2017>, <Huawei Technologies Co., Ltd>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Notice of Export Control Law
 * ===============================================
 * Huawei LiteOS may be subject to applicable export control laws and regulations, which might
 * include those applicable to Huawei LiteOS of U.S. and the country in which you are located.
 * Import, export and usage of Huawei LiteOS in any manner by you shall be in compliance with such
 * applicable export control laws and regulations.
 *---------------------------------------------------------------------------*/

#ifndef _HWLITEOS_SHELL_LK_H__
#define _HWLITEOS_SHELL_LK_H__

/**@defgroup los_lk lk
 * @ingroup kernel
 */
#include "stdarg.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
* @ingroup los_lk
* define sys default print level
* 0:TRACE_EMG 1:TRACE_COMMOM 2:TRACE_ERROR 3:TRACE_WARN 4:TRACE_INFO 5:TRACE_DEBUG
*/
#define TRACE_DEFAULT TRACE_ERROR

/**
*@ingroup los_lk
*@brief Define an printf handling function hook.
*
*@par Description:
*This API is used to define the printf handling function hook.
*@attention None.
*
*@param None.
*
*@retval None.
*
*@par Dependency:
*los_lk.h: the header file that contains the API declaration.
*@see None.
*@since Huawei LiteOS V200R001C00
*/
typedef void (* LK_FUNC)(int l_evel, const char *file, const char *func, int line, const char *fmt, va_list ap);

/**
 *@ingroup los_lk
 *@brief print log.
 *
 *@par Description:
 *<ul>
 *<li>This API is used to allocate memory blocks of specified size and of which the starting addresses are aligned on a specified boundary and update module mem used.</li>
 *</ul>
 *
 *@param  l_evel       [IN] print level.
 *@param  file      [IN] means which file calls print func.
 *@param  func  [IN] means which func calls print func.
 *@param  line   [IN] means which line calls print func.
 *@param  fmt   [IN] other infomation by user define
 *
 *@retval NONE
 *@par Dependency:
 *<ul><li>los_lk.h: the header file that contains the API declaration.</li></ul>
 *@since Huawei LiteOS V200R001C00
 */
extern void LOS_LkPrint(int l_evel, const char *file, const char *func, int line, const char *fmt, ...);

/**
 *@ingroup los_lk
 *@brief register print func.
 *
 *@par Description:
 *<ul>
 *<li>This API is used to allocate memory blocks of specified size and of which the starting addresses are aligned on a specified boundary and update module mem used.</li>
 *</ul>
 *
 *@param  LK_FUNC       [IN] the print func.
 *
 *@retval NONE
 *@par Dependency:
 *<ul><li>los_lk.h: the header file that contains the API declaration.</li></ul>
 *@since Huawei LiteOS V200R001C00
 */
extern void LOS_LkRegHook(LK_FUNC hook);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif    /*_HWLITEOS_SHELL_LK_H__*/