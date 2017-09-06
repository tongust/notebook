g++ -D_GNU_SOURCE -I./tlpi-dist/lib/ $1  ./tlpi-dist/libtlpi.a -o main -fpermissive -std=c++11
./main 2 t
