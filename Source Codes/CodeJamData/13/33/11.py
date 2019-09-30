class Attack:
	w = 0
	e = 0
	s = 0
	d = 0
	def __init__(self,w,e,s,d):
		self.w = w
		self.e = e
		self.s = s
		self.d = d
	def toStr(self):
		return "attack w=%d e=%d s=%d d=%d"%(self.w,self.e,self.s,self.d)

def raiseWall(wall,center,toRaise):
	for i in range(len(toRaise)):
		for j in range(toRaise[i][0],toRaise[i][1]):
			wall[j+center] = max(wall[j+center],toRaise[i][2])

def success(wall,center,attack):
	for i in range(attack.w,attack.e):
		if wall[i+center]<attack.s:
			return True
	return False

for T in range(int(raw_input())):
	N = int(raw_input())
	attacks = []
	for i in range(N):
		data = map(int,raw_input().split())
		di = data[0]
		ni = data[1]
		wi = data[2]
		ei = data[3]
		si = data[4]
		delta_di = data[5]
		delta_pi = data[6]
		delta_si = data[7]
		for j in range(ni):
			attacks.append(Attack(wi+j*delta_pi,ei+j*delta_pi,si+j*delta_si,di+j*delta_di))
	attacks = sorted(attacks,key=lambda attack: attack.d)
	wall = [0]*500
	center = 250
	toRaise = []
	lastAttack = -1
	sucAttacks = 0
	for i in range(len(attacks)):
		attack = attacks.pop(0)
#		print "processing "+attack.toStr()
		if attack.d>lastAttack:
			raiseWall(wall,center,toRaise)
			toRaise = []
		if success(wall,center,attack):
			#print attack.toStr()+" successfull"
			toRaise.append([attack.w,attack.e,attack.s])
			sucAttacks+=1
		lastAttack = attack.d
		
	print "Case #%d: %d"%(T+1,sucAttacks)
