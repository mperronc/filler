champion="players/mperronc.filler"

cd resources
for filler in players/*
do
	if [ "$filler" != "players/champely.filler" -a "$filler" != "$champion" ]
	then
		echo ""
		echo "VS. $filler"
		echo ""
		echo "MAP 00 P1 SIDE"
		for i in {1..5}
		do
			./filler_vm -f maps/map00 -p1 $champion -p2 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
		done
		echo ""
		echo "MAP 00 P2 SIDE"
		for i in {1..5}
		do
			./filler_vm -f maps/map00 -p2 $champion -p1 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
		done
		echo ""
		echo "MAP 01 P1 SIDE"
		for i in {1..5}
		do
			./filler_vm -f maps/map01 -p1 $champion -p2 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
		done
		echo ""
		echo "MAP 01 P2 SIDE"
		for i in {1..5}
		do
			./filler_vm -f maps/map01 -p2 $champion -p1 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
		done
		#echo ""
		#echo "MAP 02 P1 SIDE"
		#./filler_vm -f maps/map02 -p1 $champion -p2 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
		#echo ""
		#echo "MAP 02 P2 SIDE"
		#./filler_vm -f maps/map02 -p2 $champion -p1 $filler -q | grep -v "#" | grep -v "launched" | cut -c 11- | paste -sd- - | bc
	fi
done
