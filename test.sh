# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 00:04:22 by maurodri          #+#    #+#              #
#    Updated: 2024/07/08 00:26:28 by maurodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ARG=""
NUM=""
for i in $(seq 10000); do
    ARG="$(seq 5 | shuf | head  -n 5)"
    RES="$(./push_swap $ARG 2> /dev/null)"
    NUM="$(wc -l <<< $RES)"
    OK="$(./checker_linux $ARG <<< $RES)"
    #echo "$RES"
    echo "num $NUM $OK" 
    #echo "$ARG"
    #if (( $NUM > 12 )); then
    #	echo "$ARG"
    #fi
    
done
