################################################
# Make file for CASIO fx-9860G SDK Addin
#
############################
# Directory defines
TCDIR = C:\Program Files\CASIO\fx-9860G SDK\OS\SH
OSDIR = C:\Program Files\CASIO\fx-9860G SDK\OS
APPDIR = E:\Anderain\fx-9860\dPicoc
OUTDIR = E:\Anderain\fx-9860\dPicoc\Debug

################
# Main Defines
SH_EXEDIR=$(TCDIR)\bin

# Hitachi SH C/C++ Compiler02 phase
SHCC02_EXE=shc.exe
SHCC02_DEP="$(OSDIR)\FX\include\fxlib.h" "interpreter.h" "picoc.h" "platform.h" "dConsole.h"

# Hitachi SH Assembler03 phase
SHASM03_EXE=asmsh.exe

# Hitachi OptLinker04 phase
SHLINK04_EXE=Optlnk.exe
SHLINK04_DEP="$(OSDIR)\FX\lib\fx9860G_library.lib"
SHLINK04_DEP2="$(OSDIR)\FX\lib\setup.obj"

#######################
# Files to build
FILE0=dPicoc
FILESRC0="$(APPDIR)\$(FILE0).c"
FILEOBJ0="$(OUTDIR)\$(FILE0).obj"
FILE1=expression
FILESRC1="$(APPDIR)\$(FILE1).c"
FILEOBJ1="$(OUTDIR)\$(FILE1).obj"
FILE2=heap
FILESRC2="$(APPDIR)\$(FILE2).c"
FILEOBJ2="$(OUTDIR)\$(FILE2).obj"
FILE3=include
FILESRC3="$(APPDIR)\$(FILE3).c"
FILEOBJ3="$(OUTDIR)\$(FILE3).obj"
FILE4=lex
FILESRC4="$(APPDIR)\$(FILE4).c"
FILEOBJ4="$(OUTDIR)\$(FILE4).obj"
FILE5=parse
FILESRC5="$(APPDIR)\$(FILE5).c"
FILEOBJ5="$(OUTDIR)\$(FILE5).obj"
FILE6=platform
FILESRC6="$(APPDIR)\$(FILE6).c"
FILEOBJ6="$(OUTDIR)\$(FILE6).obj"
FILE7=table
FILESRC7="$(APPDIR)\$(FILE7).c"
FILEOBJ7="$(OUTDIR)\$(FILE7).obj"
FILE8=type
FILESRC8="$(APPDIR)\$(FILE8).c"
FILEOBJ8="$(OUTDIR)\$(FILE8).obj"
FILE9=variable
FILESRC9="$(APPDIR)\$(FILE9).c"
FILEOBJ9="$(OUTDIR)\$(FILE9).obj"
FILE10=library_fx9860
FILESRC10="$(APPDIR)\platform\$(FILE10).c"
FILEOBJ10="$(OUTDIR)\$(FILE10).obj"
FILE11=platform_fx9860
FILESRC11="$(APPDIR)\platform\$(FILE11).c"
FILEOBJ11="$(OUTDIR)\$(FILE11).obj"
FILE12=ctype
FILESRC12="$(APPDIR)\cstdlib\$(FILE12).c"
FILEOBJ12="$(OUTDIR)\$(FILE12).obj"
FILE13=errno
FILESRC13="$(APPDIR)\cstdlib\$(FILE13).c"
FILEOBJ13="$(OUTDIR)\$(FILE13).obj"
FILE14=math
FILESRC14="$(APPDIR)\cstdlib\$(FILE14).c"
FILEOBJ14="$(OUTDIR)\$(FILE14).obj"
FILE15=stdbool
FILESRC15="$(APPDIR)\cstdlib\$(FILE15).c"
FILEOBJ15="$(OUTDIR)\$(FILE15).obj"
FILE16=stdlib
FILESRC16="$(APPDIR)\cstdlib\$(FILE16).c"
FILEOBJ16="$(OUTDIR)\$(FILE16).obj"
FILE17=string
FILESRC17="$(APPDIR)\cstdlib\$(FILE17).c"
FILEOBJ17="$(OUTDIR)\$(FILE17).obj"
FILE18=dConsole
FILESRC18="$(APPDIR)\$(FILE18).c"
FILEOBJ18="$(OUTDIR)\$(FILE18).obj"
FILE19=clibrary
FILESRC19="$(APPDIR)\$(FILE19).c"
FILEOBJ19="$(OUTDIR)\$(FILE19).obj"
FILE20=stdio
FILESRC20="$(APPDIR)\cstdlib\$(FILE20).c"
FILEOBJ20="$(OUTDIR)\$(FILE20).obj"
FILE21=fxlib
FILESRC21="$(APPDIR)\fxlib\$(FILE21).c"
FILEOBJ21="$(OUTDIR)\$(FILE21).obj"
RFILE=FXADDINror
USERALLOBJ=$(FILEOBJ0) $(FILEOBJ1) $(FILEOBJ2) $(FILEOBJ3) $(FILEOBJ4) $(FILEOBJ5) $(FILEOBJ6) $(FILEOBJ7) $(FILEOBJ8) $(FILEOBJ9) \
      $(FILEOBJ10) $(FILEOBJ11) $(FILEOBJ12) $(FILEOBJ13) $(FILEOBJ14) $(FILEOBJ15) $(FILEOBJ16) $(FILEOBJ17) $(FILEOBJ18) $(FILEOBJ19) \
      $(FILEOBJ20) $(FILEOBJ21)

#######################
# nmake "all" statement

ALL:  SH_ENV \
	$(USERALLOBJ) \
	$(OUTDIR)\$(RFILE).bin \

####################
# Description blocks

!MESSAGE %3#C$z`&'0?
!MESSAGE
!MESSAGE Executing Hitachi SH C/C++ Compiler/Assembler phase
!MESSAGE

SH_ENV : 
	set SHC_INC=$(TCDIR)\include
	set PATH=$(TCDIR)\bin
	set SHC_LIB=$(TCDIR)\bin
	set SHC_TMP=$(OUTDIR)

$(FILEOBJ0) : $(FILESRC0) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ0)
-show=source
-listfile="$(OUTDIR)\$(FILE0).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC0)
-lang=c
-nologo
-debug
<<

$(FILEOBJ1) : $(FILESRC1) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ1)
-show=source
-listfile="$(OUTDIR)\$(FILE1).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC1)
-lang=c
-nologo
-debug
<<

$(FILEOBJ2) : $(FILESRC2) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ2)
-show=source
-listfile="$(OUTDIR)\$(FILE2).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC2)
-lang=c
-nologo
-debug
<<

$(FILEOBJ3) : $(FILESRC3) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ3)
-show=source
-listfile="$(OUTDIR)\$(FILE3).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC3)
-lang=c
-nologo
-debug
<<

$(FILEOBJ4) : $(FILESRC4) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ4)
-show=source
-listfile="$(OUTDIR)\$(FILE4).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC4)
-lang=c
-nologo
-debug
<<

$(FILEOBJ5) : $(FILESRC5) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ5)
-show=source
-listfile="$(OUTDIR)\$(FILE5).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC5)
-lang=c
-nologo
-debug
<<

$(FILEOBJ6) : $(FILESRC6) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ6)
-show=source
-listfile="$(OUTDIR)\$(FILE6).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC6)
-lang=c
-nologo
-debug
<<

$(FILEOBJ7) : $(FILESRC7) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ7)
-show=source
-listfile="$(OUTDIR)\$(FILE7).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC7)
-lang=c
-nologo
-debug
<<

$(FILEOBJ8) : $(FILESRC8) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ8)
-show=source
-listfile="$(OUTDIR)\$(FILE8).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC8)
-lang=c
-nologo
-debug
<<

$(FILEOBJ9) : $(FILESRC9) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ9)
-show=source
-listfile="$(OUTDIR)\$(FILE9).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC9)
-lang=c
-nologo
-debug
<<

$(FILEOBJ10) : $(FILESRC10) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ10)
-show=source
-listfile="$(OUTDIR)\$(FILE10).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC10)
-lang=c
-nologo
-debug
<<

$(FILEOBJ11) : $(FILESRC11) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ11)
-show=source
-listfile="$(OUTDIR)\$(FILE11).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC11)
-lang=c
-nologo
-debug
<<

$(FILEOBJ12) : $(FILESRC12) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ12)
-show=source
-listfile="$(OUTDIR)\$(FILE12).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC12)
-lang=c
-nologo
-debug
<<

$(FILEOBJ13) : $(FILESRC13) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ13)
-show=source
-listfile="$(OUTDIR)\$(FILE13).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC13)
-lang=c
-nologo
-debug
<<

$(FILEOBJ14) : $(FILESRC14) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ14)
-show=source
-listfile="$(OUTDIR)\$(FILE14).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC14)
-lang=c
-nologo
-debug
<<

$(FILEOBJ15) : $(FILESRC15) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ15)
-show=source
-listfile="$(OUTDIR)\$(FILE15).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC15)
-lang=c
-nologo
-debug
<<

$(FILEOBJ16) : $(FILESRC16) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ16)
-show=source
-listfile="$(OUTDIR)\$(FILE16).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC16)
-lang=c
-nologo
-debug
<<

$(FILEOBJ17) : $(FILESRC17) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ17)
-show=source
-listfile="$(OUTDIR)\$(FILE17).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC17)
-lang=c
-nologo
-debug
<<

$(FILEOBJ18) : $(FILESRC18) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ18)
-show=source
-listfile="$(OUTDIR)\$(FILE18).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC18)
-lang=c
-nologo
-debug
<<

$(FILEOBJ19) : $(FILESRC19) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ19)
-show=source
-listfile="$(OUTDIR)\$(FILE19).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC19)
-lang=c
-nologo
-debug
<<

$(FILEOBJ20) : $(FILESRC20) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ20)
-show=source
-listfile="$(OUTDIR)\$(FILE20).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC20)
-lang=c
-nologo
-debug
<<

$(FILEOBJ21) : $(FILESRC21) $(SHCC02_DEP)
	"$(SH_EXEDIR)\$(SHCC02_EXE)" -subcommand=<<
-cpu=sh3
-include="$(OSDIR)\FX\include","$(APPDIR)"
-objectfile=$(FILEOBJ21)
-show=source
-listfile="$(OUTDIR)\$(FILE21).lst"
-size
-noinline
-chgincpath
-errorpath
$(FILESRC21)
-lang=c
-nologo
-debug
<<

!MESSAGE
!MESSAGE Executing Hitachi OptLinker04 phase
!MESSAGE

"$(OUTDIR)\$(RFILE).bin" : $(USERALLOBJ) $(SHLINK04_DEP2) $(SHLINK04_DEP)
	"$(SH_EXEDIR)\$(SHLINK04_EXE)" -subcommand=<<
noprelink
sdebug
rom D=R
nomessage 
list "$(OUTDIR)\$(RFILE).map"
show symbol
nooptimize
start P_TOP,P,C,D,C$VTBL,C$INIT/0300200,B_BR_Size,B,R/08100000
fsymbol P
nologo
input $(USERALLOBJ)
input $(SHLINK04_DEP2)
library $(SHLINK04_DEP)
output "$(OUTDIR)\$(RFILE).abs"
-nomessage=1100
end
input "$(OUTDIR)\$(RFILE).abs"
form binary
output "$(OUTDIR)\$(RFILE).bin"
exit
<<

