#!/bin/sh

echo "--------------------"
for file in tests/*.dat
do
    num=`echo "$file" | egrep -o '[0-9]+'`
    ./stu tests/s${num}.dat > tests/${num}.out
    if diff tests/${num}.out tests/${num}.exp
    then
        echo "Passed test $num"
    else
        echo "Failed test $num"
    fi
    echo "--------------------"
done
