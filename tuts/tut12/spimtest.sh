#!/bin/sh

echo "--------------------"
for file in tests/*.s
do
    num=`echo "$file" | egrep -o '[0-9]+'`
    cat main.s q1.s $file > exe.s
    spim -file exe.s | tail -n +5 | sed -E 's/.*exceptions\.s/Loaded: \/home\/class\/lib\/exceptions\.s/g' > tests/${num}.out
    if diff tests/${num}.out tests/${num}.exp
    then
        echo "Passed test $num"
    else
        echo "Failed test $num"
    fi
    echo "--------------------"
done
