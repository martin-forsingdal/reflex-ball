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
#   -strict -usrinc:"C:\Users\martin\Desktop\GitHub\include" -NOwatch
#   -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\martin\Desktop\GitHub\ReflexBall_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\martin\Desktop\GitHub\ReflexBall_Debug.asmsw

OUTDIR = C:\Users\martin\Desktop\GitHub\

Debug: ReflexBall

deltarget: 
	@if exist C:\Users\martin\Desktop\GitHub\ReflexBall.lod  \
            del C:\Users\martin\Desktop\GitHub\ReflexBall.lod

clean: 
	@if exist C:\Users\martin\Desktop\GitHub\ReflexBall.lod  \
            del C:\Users\martin\Desktop\GitHub\ReflexBall.lod
	@if exist C:\Users\martin\Desktop\GitHub\zsldevinit.obj  \
            del C:\Users\martin\Desktop\GitHub\zsldevinit.obj
	@if exist C:\Users\martin\Desktop\GitHub\main.obj  \
            del C:\Users\martin\Desktop\GitHub\main.obj
	@if exist C:\Users\martin\Desktop\GitHub\ansi.obj  \
            del C:\Users\martin\Desktop\GitHub\ansi.obj
	@if exist C:\Users\martin\Desktop\GitHub\board.obj  \
            del C:\Users\martin\Desktop\GitHub\board.obj
	@if exist C:\Users\martin\Desktop\GitHub\fixpoint.obj  \
            del C:\Users\martin\Desktop\GitHub\fixpoint.obj
	@if exist C:\Users\martin\Desktop\GitHub\LUT.obj  \
            del C:\Users\martin\Desktop\GitHub\LUT.obj
	@if exist C:\Users\martin\Desktop\GitHub\tri.obj  \
            del C:\Users\martin\Desktop\GitHub\tri.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\martin\Desktop\GitHub\zsldevinit.obj  \
            C:\Users\martin\Desktop\GitHub\main.obj  \
            C:\Users\martin\Desktop\GitHub\ansi.obj  \
            C:\Users\martin\Desktop\GitHub\board.obj  \
            C:\Users\martin\Desktop\GitHub\fixpoint.obj  \
            C:\Users\martin\Desktop\GitHub\LUT.obj  \
            C:\Users\martin\Desktop\GitHub\tri.obj

ReflexBall: $(OBJS)
	 $(LINK)  @C:\Users\martin\Desktop\GitHub\ReflexBall_Debug.linkcmd

C:\Users\martin\Desktop\GitHub\zsldevinit.obj :  \
            C:\Users\martin\Desktop\GitHub\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\martin\Desktop\GitHub\zsldevinit.asm

C:\Users\martin\Desktop\GitHub\main.obj :  \
            C:\Users\martin\Desktop\GitHub\Project\main.c  \
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
            C:\Users\martin\Desktop\GitHub\include\LUT.h  \
            C:\Users\martin\Desktop\GitHub\include\ansi.h  \
            C:\Users\martin\Desktop\GitHub\include\board.h  \
            C:\Users\martin\Desktop\GitHub\include\charset.h  \
            C:\Users\martin\Desktop\GitHub\include\fixpoint.h  \
            C:\Users\martin\Desktop\GitHub\include\tri.h
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\Project\main.c

C:\Users\martin\Desktop\GitHub\ansi.obj :  \
            C:\Users\martin\Desktop\GitHub\include\src\ansi.c  \
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
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\include\src\ansi.c

C:\Users\martin\Desktop\GitHub\board.obj :  \
            C:\Users\martin\Desktop\GitHub\include\src\board.c  \
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
            C:\Users\martin\Desktop\GitHub\include\ansi.h
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\include\src\board.c

C:\Users\martin\Desktop\GitHub\fixpoint.obj :  \
            C:\Users\martin\Desktop\GitHub\include\src\fixpoint.c
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\include\src\fixpoint.c

C:\Users\martin\Desktop\GitHub\LUT.obj :  \
            C:\Users\martin\Desktop\GitHub\include\src\LUT.c  \
            C:\Users\martin\Desktop\GitHub\include\LUT.h
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\include\src\LUT.c

C:\Users\martin\Desktop\GitHub\tri.obj :  \
            C:\Users\martin\Desktop\GitHub\include\src\tri.c  \
            C:\Users\martin\Desktop\GitHub\include\LUT.h  \
            C:\Users\martin\Desktop\GitHub\include\fixpoint.h
	 $(CC)  $(CFLAGS) C:\Users\martin\Desktop\GitHub\include\src\tri.c

