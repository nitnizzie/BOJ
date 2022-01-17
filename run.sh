if [ $1 ]; then
    if [ -d "$1" ]; then
        g++ -o $1/$1.out $1/$1.cpp
        ./$1/$1.out
    else
        echo "create new file on /$1"
        mkdir $1
        #touch $1/$1.cpp
        cp sample.cpp $1/$1.cpp
    fi
else
    echo "usage: ./run.sh <num>"
fi