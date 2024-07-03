# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 00:04:22 by maurodri          #+#    #+#              #
#    Updated: 2024/07/02 21:33:43 by maurodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ARG=""
NUM=""
for i in $(seq 1000); do
    ARG="$(seq 1000000 | shuf | head  -n 5)"
    NUM="$(./push_swap $ARG 2> /dev/null | wc -l)"
    OK="$(./push_swap $ARG 2> /dev/null | ./checker_linux $ARG)"
    #echo "$RES"
    echo "num $NUM $OK" 
    #echo "$ARG"
    if (( $NUM > 12 )); then
    	echo "$ARG"
    fi
    
done
