cat /etc/passwd |grep -v '^#' | sed 's/[:].*//' | awk 'NR==1 || NR%2==0' | rev | sort -r | sed $FT_LINE1','$FT_LINE2'!d' | tr '\n' ',' | sed 's/.$/./' | sed 's/,/, /g' | tr -d '\n'