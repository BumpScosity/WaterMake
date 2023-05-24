@echo off

rem Parser
cd src && cd parser

set flags= -c -Wno-deprecated-declarations -Wno-incompatible-pointer-types-discards-qualifiers
set linker-flags=/force:unresolved /defaultlib:msvcrt.lib /subsystem:Console

clang %flags% call.c -o ../../call.o
clang %flags% other.c -o ../../other.o
clang %flags% parser.c -o ../../parser.o
rem Parser

rem Misc
cd .. && cd misc

clang %flags% free.c -o ../../free.o
clang %flags% function.c -o ../../function.o

rem Misc

rem Lexer
cd .. && cd lexer
clang %flags% lexer.c -o ../../lexer.o
rem Lexer

rem Main
cd ..
clang %flags% main.c -o ../main.o
rem Main

rem WaterMake

set parser=call.o other.o parser.o
set misc=free.o function.o
set link=%parser% %misc% main.o lexer.o

cd ..
lld-link %linker-flags% /out:WaterMake.exe %link%

del free.o
del function.o
del call.o
del other.o
del parser.o
del lexer.o
del main.o

rem WaterMake