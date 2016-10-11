from random import shuffle
from random import randint

c_NUMOFPAIRS = 10

###generate initial lists#####################
bolts = []
for num in range(c_NUMOFPAIRS):
	newBolt = randint(1,c_NUMOFPAIRS * 10)
	while newBolt in bolts:     ## ensures bolt size is unique
		newBolt = randint(0,c_NUMOFPAIRS * 10)
	bolts.append(newBolt)

nuts = bolts[:]
shuffle(nuts)
shuffle(bolts)

print ("Original pile of nuts: ", nuts)
print ("Original pile of bolts: ", bolts)
##############################################

firstBolt = bolts[0]
bolts.remove(firstBolt)
sortedNuts = [[],[]]
finalPairs = []

for nut in nuts:
	if nut != firstBolt:
		sortedNuts[nut > firstBolt].append(nut)
	else:
		finalPairs.append((firstBolt, nut))
		firstNut = nut


for bolt in bolts:
	biggerThan = bolt > firstNut # determine which list to look in
	nut = -1
	nutNum = 0
	while nut != bolt:
		nut = sortedNuts[biggerThan][nutNum]
		nutNum += 1
	finalPairs.append((bolt, nut))
	sortedNuts[biggerThan].remove(nut)

print ("\nFinal sorted pairs: ")
for pair in finalPairs:
	print (pair)
input("\nPress any key to quit... ")


	
	
