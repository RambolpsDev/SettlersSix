mkdir build-win
cd build-win
cmake -G "Ninja" -DCMAKE_C_COMPILER=cl.exe -DCMAKE_CXX_COMPILER=cl.exe -DCMAKE_BUILD_TYPE=Release ..
ninja
robocopy "..\Assets" ".\Assets" /E /NFL /NDL /NJH /NJS /NC /NS
copy ".\vendored\SDL3\SDL3.dll" SDL3.dll
SettlersSix.exe