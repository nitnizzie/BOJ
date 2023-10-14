if [ $1 ]; then
    if [ -d "src/$1" ]; then
        g++ -std=c++11 -o src/$1/$1.out src/$1/$1.cpp
        ./src/$1/$1.out
    else
        echo "create new file on src/$1"
        mkdir src/$1
        cp sample.cpp src/$1/$1.cpp
    fi
else
    echo "usage: ./run.sh <num>"
fi