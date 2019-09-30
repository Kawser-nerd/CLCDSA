import numpy as np

def FactorialMod (n):
	res = 1
	for i in range(1, n+1):
		res = (res * i) % 1000000007

	return res

def VerifyCars (cars):
	for car in cars:
		visible = set([car[0]])
		streak = car[0]
		for i in car:
			if i != streak and i in visible:
				return False
			if i != streak:
				streak = i
				visible.add(i)
	return True

def FindCollisionLetter (cars):
	sets = []
	for car in cars:
		sets.append(set(car))

	for k in range(len(sets)):
		for l in range(k):
			s1 = sets[k]
			s2 = sets[l]
			inter = s1 & s2

			if len(inter) != 0:
				return list(inter)[0]

	return None

def CombineOnLetter (cars, letter):
	# Find all the cars with the required letter
	fronter = []
	ender = []
	middler = []
	rusty = []
	rest = []

	for car in cars:
		available = set(car)
		if letter in available:
			if len(available) == 1:
				middler.append(car)
			elif car[0] == letter:
				fronter.append(car)
			elif car[-1] == letter:
				ender.append(car)
			else:
				rusty.append(car)
		else:
			rest.append(car)

	#print fronter
	#print middler
	#print ender
	#print rusty

	if len(rusty) > 0:
		return (cars, 0)

	if len(fronter) > 1:
		return (cars, 0)

	if len(ender) > 1:
		return (cars, 0)

	combinedcar = ""
	if len(ender) > 0:
		combinedcar += ender[0]
	for s in middler:
		combinedcar += s
	if len(fronter) > 0:
		combinedcar += fronter[0]

	newcars = rest + [combinedcar]

	return (newcars, FactorialMod(len(middler)))


def ProcessOne():
	N = int(raw_input())
	cars = raw_input().split()

	if not VerifyCars(cars):
		print ("Case #%(id)s: %(res)s" % {"id" : i+1, "res" : 0})
		return

	res = 1
	while FindCollisionLetter(cars) != None:
		letter = FindCollisionLetter(cars)
		newcars, mult = CombineOnLetter(cars, letter)
		cars = newcars
		res = (res * mult) % 1000000007
		if res == 0:
			break

		# Verify once more if the sequence is correct
		if not VerifyCars(cars):
			print ("Case #%(id)s: %(res)s" % {"id" : i+1, "res" : 0})
			return

	# Now any order will do - there are no more letter intersections
	res = (res * FactorialMod(len(cars))) % 1000000007

	print ("Case #%(id)s: %(res)s" % {"id" : i+1, "res" : res})


T = int(raw_input())

for i in range(T):
	ProcessOne()




