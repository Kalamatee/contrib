/*
 * Mesa 3-D graphics library
 * Version:  7.1
 *
 * Copyright (C) 1999-2008  Brian Paul   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


/**
 * \mainpage Mesa GL API Module
 *
 * \section GLAPIIntroduction Introduction
 *
 * The Mesa GL API module is responsible for dispatching all the
 * gl*() functions.  All GL functions are dispatched by jumping through
 * the current dispatch table (basically a struct full of function
 * pointers.)
 *
 * A per-thread current dispatch table and per-thread current context
 * pointer are managed by this module too.
 *
 * This module is intended to be non-Mesa-specific so it can be used
 * with the X/DRI libGL also.
 */


#ifndef _GLAPI_H
#define _GLAPI_H

#define GL_GLEXT_PROTOTYPES

#include "GL/gl.h"
#include "GL/glext.h"
#include "glthread.h"


struct _glapi_table;

#if defined(__AROS__) 
#if defined(AROS_MESA_SHARED)

#if defined(__i386__)
register struct MesaBase * REGMesaBase __asm__("ebx");
#elif defined(__x86_64__)
register struct MesaBase * REGMesaBase __asm__("rbx");
#elif defined(PPC) || defined (__powerpc__)
/*
 * r11 or r12 emit call clobbered register warnings
 * r13 works as well, but is small data area pointer
 * in SysV ABI, which we might use in the future
 */
register struct MesaBase * REGMesaBase __asm__("r14");
#else
#error Select register for your architecture
#endif

#define PUT_MESABASE_IN_REG REGMesaBase = (struct MesaBase *)MesaBase;
extern void                     **GETMESABASECTX(void);
extern struct _glapi_table      **GETMESABASEDDISPATCH(void);
#else

#define PUT_MESABASE_IN_REG

#endif
#endif

typedef void (*_glapi_proc)(void); /* generic function pointer */

typedef void (*_glapi_warning_func)(void *ctx, const char *str, ...);


#if defined(USE_MGL_NAMESPACE)
#define _glapi_set_dispatch _mglapi_set_dispatch
#define _glapi_get_dispatch _mglapi_get_dispatch
#define _glapi_set_context _mglapi_set_context
#define _glapi_get_context _mglapi_get_context
#define _glapi_Context _mglapi_Context
#define _glapi_Dispatch _mglapi_Dispatch
#endif


/*
 * Number of extension functions which we can dynamically add at runtime.
 */
#define MAX_EXTENSION_FUNCS 300


/**
 ** Define the GET_CURRENT_CONTEXT() macro.
 ** \param C local variable which will hold the current context.
 **/
#if defined (GLX_USE_TLS)

const extern void *_glapi_Context;
const extern struct _glapi_table *_glapi_Dispatch;

extern __thread void * _glapi_tls_Context
    __attribute__((tls_model("initial-exec")));

# define GET_CURRENT_CONTEXT(C)  GLcontext *C = (GLcontext *) _glapi_tls_Context

#else

#if defined(__AROS__) && defined(AROS_MESA_SHARED)
# if defined(USE_MGL_NAMESPACE)
#  define _mglapi_Context *(GETMESABASECTX())
#  define _mglapi_Dispatch *(GETMESABASEDDISPATCH())
# else
#  define _glapi_Context *(GETMESABASECTX())
#  define _glapi_Dispatch *(GETMESABASEDDISPATCH())
# endif
#else
extern void *_glapi_Context;
extern struct _glapi_table *_glapi_Dispatch;
#endif

# ifdef THREADS
#  define GET_CURRENT_CONTEXT(C)  GLcontext *C = (GLcontext *) (_glapi_Context ? _glapi_Context : _glapi_get_context())
# else
#  define GET_CURRENT_CONTEXT(C)  GLcontext *C = (GLcontext *) _glapi_Context
# endif

#endif /* defined (GLX_USE_TLS) */


/**
 ** GL API public functions
 **/

extern void
_glapi_noop_enable_warnings(GLboolean enable);

extern void
_glapi_set_warning_func(_glapi_warning_func func);

extern void
_glapi_check_multithread(void);


extern void
_glapi_set_context(void *context);


extern void *
_glapi_get_context(void);


extern void
_glapi_set_dispatch(struct _glapi_table *dispatch);


extern struct _glapi_table *
_glapi_get_dispatch(void);


extern int
_glapi_begin_dispatch_override(struct _glapi_table *override);


extern void
_glapi_end_dispatch_override(int layer);


struct _glapi_table *
_glapi_get_override_dispatch(int layer);


extern GLuint
_glapi_get_dispatch_table_size(void);


extern void
_glapi_check_table(const struct _glapi_table *table);


extern int
_glapi_add_dispatch( const char * const * function_names,
		     const char * parameter_signature );

extern GLint
_glapi_get_proc_offset(const char *funcName);


extern _glapi_proc
_glapi_get_proc_address(const char *funcName);


extern const char *
_glapi_get_proc_name(GLuint offset);


#endif
