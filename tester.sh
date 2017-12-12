./a.out $1 > result
cmp -s result $1
if [ $? = 0 ]
then
	echo "c'est tout juste !"
else
	echo "Ce n'est pas juste."
	cmp result $1
fi
rm result
