# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 00:04:22 by maurodri          #+#    #+#              #
#    Updated: 2024/07/11 01:45:20 by maurodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG=""
NUM=""
CASES="3 5 100 500"
declare -A LIMITS
LIMITS["3"]="2"
LIMITS["5"]="11"
LIMITS["100"]="899"
LIMITS["500"]="6100"
for CASE in $CASES; do
	echo "case: $CASE"
	for i in $(seq 100); do
		ARG="$(seq 1000000 | shuf | head  -n $CASE)"
		RES="$(./push_swap $ARG 2> /dev/null)"
		NUM="$(wc -l <<< $RES)"
		OK="$([[ $RES == "" ]] && echo OK || ./checker_linux $ARG <<< $RES)"
		#echo "$RES"
		echo "num $NUM $OK" 
		#echo "$ARG"
		if (( $NUM > LIMITS["$CASE"] )); then
			echo "$ARG" | tr '\n' ' '
			echo ""
		fi
	done
done

