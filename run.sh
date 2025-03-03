mkdir -p build-deb
cd build-deb
mkdir -p Assets
cmake -G "Ninja" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release ..
ninja
cd ..
pwd
cp -R -u -p Assets build-deb
cd build-deb
./SettlersSix
