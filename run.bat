cmake -S . -B build
cmake --build build
copy build\Debug\program.exe build\program.exe
cd build
program.exe
pause