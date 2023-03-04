cmake -S ./ -B build
cd build
make
cd src
./PL0 < ../../src/in.txt
