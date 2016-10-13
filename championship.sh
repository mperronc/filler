echo "FILLER CHAMPIONSHIP !"
echo "Enter the name of the .filler to test against others :"

read champion

cd resources
for filler in players/*
do
	for i in {1..1}
	do
	./filler_vm -f maps/map01 -p1 "players/$champion" -p2 $filler -q | grep -v "#"
	./filler_vm -f maps/map01 -p2 "players/$champion" -p1 $filler -q | grep -v "#"
	done
done
