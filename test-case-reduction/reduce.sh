#!/bin/bash

#get number of test cases
n=$(wc -l < test/T) 

#generate .gcov file for each test case
for ((i=1;i<=n;i++)); do
    g++ -Wall -g -fprofile-arcs -ftest-coverage test/P.cpp -o b
    sed -n "${i} p" < test/T > tmp
    ./b < tmp
    gcov -b -c P

    #grep out branch details
    grep branch P.cpp.gcov > tmp

    #assign key value to each branch
    nl tmp > tmp.txt
    
    #grep out branch keys with frequency>0
    grep taken tmp.txt | awk '{if($5>0)print($1)}' > "${i}"
    rm -rf  b  *.gcov *.gcno *.gcda *.bb *.gcbb
done    

#get number of branches and number of test cases
echo $(wc -l < tmp) > "b.txt"
echo $n > "n.txt"  

#run algorithm in c++
g++ algo.cpp -o output
./output 

#clean up
for ((i=1;i<=n;i++)); do
    rm -rf ${i} 
done    

#assign key value to test cases
nl test/T > temp
> test/S 

#read the keys of optimal test cases and print corresponding test pair
while IFS= read -r x 
do 
    grep -w $x temp | awk '{print $2,$3'} >> test/S
done < red.txt

#clean up
rm -rf tmp tmp.txt b.txt n.txt

rm -rf red.txt temp

rm -rf output a.out
