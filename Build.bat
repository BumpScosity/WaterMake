@echo off

rem Parser
cd src && cd parser

set flags= -c -Wno-deprecated-declarations -Wno-incompatible-pointer-types-discards-qualifiers
set linker-flags=/force:unresolved /defaultlib:msvcrt.lib /subsystem:Console

clang %flags% call.c -o ../../call.o
clang %flags% inc.c -o ../../inc.o
clang %flags% callif.c -o ../../callif.o
clang %flags% other.c -o ../../other.o
clang %flags% parser.c -o ../../parser.o
rem Parser

rem Misc
cd .. && cd misc

clang %flags% free.c -o ../../free.o
clang %flags% function.c -o ../../function.o

rem Misc

rem Variable
cd .. && cd variable

clang %flags% variables.c -o ../../variables.o 

rem Variable

rem Lexer
cd .. && cd lexer
clang %flags% lexer.c -o ../../lexer.o
rem Lexer

rem Main
cd ..
clang %flags% main.c -o ../main.o
rem Main

rem WaterMake

set parser=call.o inc.o callif.o other.o parser.o
set misc=free.o function.o
set variable=variables.o
set link=%parser% %misc% %variable% main.o lexer.o

cd ..
lld-link %linker-flags% /out:WaterMake.exe %link%

del free.o
del function.o
del variables.o 
del call.o
del inc.o
del callif.o
del other.o
del parser.o
del lexer.o
del main.o

rem WaterMake