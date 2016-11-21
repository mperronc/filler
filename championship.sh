echo "FILLER CHAMPIONSHIP !"
echo "Enter the name of the .filler to test against others :"

read champion

cd resources
for filler in players/*
do
	echo "VS. $filler"
	echo "MAP 00 P1 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map00 -p1 "players/$champion" -p2 $filler -q | grep -v "#"
	done
	echo "MAP 00 P2 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map00 -p2 "players/$champion" -p1 $filler -q | grep -v "#"
	done
	echo "MAP 01 P1 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map01 -p1 "players/$champion" -p2 $filler -q | grep -v "#"
	done
	echo "MAP 01 P2 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map01 -p2 "players/$champion" -p1 $filler -q | grep -v "#"
	done
	echo "MAP 02 P1 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map02 -p1 "players/$champion" -p2 $filler -q | grep -v "#"
	done
	echo "MAP 02 P2 SIDE"
	for i in {1..5}
	do
		./filler_vm -f maps/map02 -p2 "players/$champion" -p1 $filler -q | grep -v "#"
	done
done
