#
# ZDS II Make File - ReflexBall, Debug
#

CC = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict -usrinc:"C:\REFLEX~1\include" -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\REFLEX~1\HENNIN~1\ReflexBall_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\REFLEX~1\HENNIN~1\ReflexBall_Debug.asmsw

OUTDIR = C:\REFLEX~1\HENNIN~1\

Debug: ReflexBall

deltarget: 
	@if exist C:\REFLEX~1\HENNIN~1\ReflexBall.lod  \
            del C:\REFLEX~1\HENNIN~1\ReflexBall.lod

clean: 
	@if exist C:\REFLEX~1\HENNIN~1\ReflexBall.lod  \
            del C:\REFLEX~1\HENNIN~1\ReflexBall.lod
	@if exist C:\REFLEX~1\HENNIN~1\zsldevinit.obj  \
            del C:\REFLEX~1\HENNIN~1\zsldevinit.obj
	@if exist C:\REFLEX~1\HENNIN~1\ansi.obj  \
            del C:\REFLEX~1\HENNIN~1\ansi.obj
	@if exist C:\REFLEX~1\HENNIN~1\board.obj  \
            del C:\REFLEX~1\HENNIN~1\board.obj
	@if exist C:\REFLEX~1\HENNIN~1\fixpoint.obj  \
            del C:\REFLEX~1\HENNIN~1\fixpoint.obj
	@if exist C:\REFLEX~1\HENNIN~1\LUT.obj  \
            del C:\REFLEX~1\HENNIN~1\LUT.obj
	@if exist C:\REFLEX~1\HENNIN~1\tri.obj  \
            del C:\REFLEX~1\HENNIN~1\tri.obj
	@if exist C:\REFLEX~1\HENNIN~1\main.obj  \
            del C:\REFLEX~1\HENNIN~1\main.obj
	@if exist C:\REFLEX~1\HENNIN~1\tiles.obj  \
            del C:\REFLEX~1\HENNIN~1\tiles.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\REFLEX~1\HENNIN~1\zsldevinit.obj  \
            C:\REFLEX~1\HENNIN~1\ansi.obj  \
            C:\REFLEX~1\HENNIN~1\board.obj  \
            C:\REFLEX~1\HENNIN~1\fixpoint.obj  \
            C:\REFLEX~1\HENNIN~1\LUT.obj  \
            C:\REFLEX~1\HENNIN~1\tri.obj  \
            C:\REFLEX~1\HENNIN~1\main.obj  \
            C:\REFLEX~1\HENNIN~1\tiles.obj

ReflexBall: $(OBJS)
	 $(LINK)  @C:\REFLEX~1\HENNIN~1\ReflexBall_Debug.linkcmd

C:\REFLEX~1\HENNIN~1\zsldevinit.obj :  \
            C:\REFLEX~1\HENNIN~1\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\REFLEX~1\HENNIN~1\zsldevinit.asm

C:\REFLEX~1\HENNIN~1\ansi.obj :  \
            C:\REFLEX~1\include\src\ansi.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\ansi.c

C:\REFLEX~1\HENNIN~1\board.obj :  \
            C:\REFLEX~1\include\src\board.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\board.c

C:\REFLEX~1\HENNIN~1\fixpoint.obj :  \
            C:\REFLEX~1\include\src\fixpoint.c
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\fixpoint.c

C:\REFLEX~1\HENNIN~1\LUT.obj :  \
            C:\REFLEX~1\include\src\LUT.c
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\LUT.c

C:\REFLEX~1\HENNIN~1\tri.obj :  \
            C:\REFLEX~1\include\src\tri.c  \
            C:\REFLEX~1\include\LUT.h  \
            C:\REFLEX~1\include\fixpoint.h
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\tri.c

C:\REFLEX~1\HENNIN~1\main.obj :  \
            C:\REFLEX~1\HENNIN~1\main.c
	 $(CC)  $(CFLAGS) C:\REFLEX~1\HENNIN~1\main.c

C:\REFLEX~1\HENNIN~1\tiles.obj :  \
            C:\REFLEX~1\include\src\tiles.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\REFLEX~1\include\ansi.h
	 $(CC)  $(CFLAGS) C:\REFLEX~1\include\src\tiles.c

