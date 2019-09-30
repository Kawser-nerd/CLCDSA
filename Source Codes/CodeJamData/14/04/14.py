import sys

def main():
	f = open(sys.argv[1])
	T = int(f.readline().strip())
	for i in range(1,T+1):
		n = int(f.readline().strip())
		myBlocks = [int(float(x)*1000000000) for x in f.readline().strip().split()]
		kenBlocks = [int(float(x)*1000000000) for x in f.readline().strip().split()]

		# Normal
		naiomi = NaiomiWar(myBlocks)
		ken = KenWar(kenBlocks)
		myPoints = 0
		for j in xrange(n):
			(myB, myTell) = naiomi.play()
			kenB = ken.play(myTell)
			if myB > kenB:
				myPoints += 1
		
		# Deceitful
		naiomi = NaiomiDeceitfulWar(myBlocks, kenBlocks)
		ken = KenWar(kenBlocks)
		myPointsDeceitful = 0
		for j in xrange(n):
			(myB, myTell) = naiomi.play()
			kenB = ken.play(myTell)
			if myB > kenB:
				myPointsDeceitful += 1
		print "Case #%d: %d %d" % (i, myPointsDeceitful, myPoints)

class NaiomiWar:
	def __init__(self, myBlocks):
		self.myBlocks = sorted(myBlocks)
		
	def play(self):
		b = self.myBlocks.pop(0)
		return (b, b)
	
class KenWar:
	def __init__(self, myBlocks):
		self.myBlocks = sorted(myBlocks)
		
	def play(self, told):
		for i in xrange(len(self.myBlocks)):
			if self.myBlocks[i] > told: # Binary search would be better
				return self.myBlocks.pop(i)
		return self.myBlocks.pop(0)
	
class NaiomiDeceitfulWar:
	def __init__(self, myBlocks, kenBlocks):
		self.myBlocks = sorted(myBlocks)
		self.kenBlocks = sorted(kenBlocks)
		self.needToLose = self.howManyShouldILose();
		self.told = set(kenBlocks)
		
	def play(self):
		if self.needToLose > 0:
			tell = self.kenBlocks.pop(-1) - 1
			while tell in self.told:
				tell -= 1
			self.told.add(tell)
			self.needToLose -= 1
			return (self.myBlocks.pop(0), tell)
		else:
			tell = self.kenBlocks[-1] + 1
			while tell in self.told:
				tell += 1
			self.told.add(tell)
			self.kenBlocks.pop(0)
			return (self.myBlocks.pop(0), tell)
			
	def howManyShouldILose(self):
		lose = 0;
		for i in reversed(xrange(len(self.myBlocks))):
			if self.myBlocks[i+lose] < self.kenBlocks[i]:
				lose += 1
		return lose;

if __name__ == '__main__':
	main()