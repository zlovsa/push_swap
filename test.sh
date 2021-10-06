for ((i=1; i<=$2; i++)); do
	ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
	if [ "$1" -lt 100 ]; then
		echo $ARG
	fi
	./push_swap $ARG | wc -l
	./push_swap $ARG | ./checker $ARG
done