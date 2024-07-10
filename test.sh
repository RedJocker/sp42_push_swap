# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 00:04:22 by maurodri          #+#    #+#              #
#    Updated: 2024/07/10 15:11:27 by maurodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ARG=""
NUM=""
CASES="3 5 100 500"
for CASE in $CASES; do
	echo "case: $CASE"
	for i in $(seq 100); do
		ARG="$(seq $CASE | shuf | head  -n $CASE)"
		RES="$(./push_swap $ARG 2> /dev/null)"
		NUM="$(wc -l <<< $RES)"
		OK="$([[ $RES == "" ]] && echo OK || ./checker_linux $ARG <<< $RES)"
		#echo "$RES"
		echo "num $NUM $OK" 
		#echo "$ARG"
		#if (( $NUM > 12 )); then
		#	echo "$ARG"
		#fi
	done
done
