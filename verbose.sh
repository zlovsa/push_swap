ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker -v -p=40 -c $ARG