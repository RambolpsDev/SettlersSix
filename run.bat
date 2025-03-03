mkdir build-win
cd build-win
cmake -G "Ninja" -DCMAKE_C_COMPILER=cl.exe -DCMAKE_CXX_COMPILER=cl.exe -DCMAKE_BUILD_TYPE=Release ..
ninja
copy "..\SDL3-3.2.6\lib\SDL3.dll" SDL3.dll
robocopy "..\Assets" ".\Assets" /E /NFL /NDL /NJH /NJS /NC /NS
SettlersSix.exe