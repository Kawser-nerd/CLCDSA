import time
engines = {}
queries = []

def solve() :
	global tt, num_a, num_b
	
	tt.sort()
	num_train_a = 0
	num_train_b = 0
	n = 0
	b_new = True
	while n < ( num_a + num_b ) :
		if tt[n][2] == 0 :
			if b_new :
				n_backup = n
				
				tt[n][2] = 1 #means done
				time = tt[n][1] # arriving + turn around time
				if tt[n][3] == 1 :
					num_train_a += 1
					type = 2
				else :
					num_train_b += 1
					type = 1
				b_new = False
			elif tt[n][3] == type :
				if tt[n][0] >= time :
					tt[n][2] = 1
					time = tt[n][1]
					if type == 1 : type =2
					else : type =1
		n += 1
		if n >= (num_a + num_b ) and b_new != True:
			b_new = True
			n = n_backup
		
	for n in range( len(tt) ):
		print tt[n]
	
	return num_train_a, num_train_b

def get_time( str ) :
	a, b = str.split(' ')
	a_h, a_m = a.split(':')
	b_h, b_m = b.split(':')
	a_ret = int(a_h)*60 + int(a_m)
	b_ret = int(b_h)*60 + int(b_m)
	
	return a_ret, b_ret
	
ps_time = time.time()
filename = "B-large"
#filename = "B-small-attempt0"
#filename = "test"

in_file = file("./"+filename+".in")
out_file = file("./"+filename+".out","w")

case_num = 0
mode = 0

tt_a = []
tt_b = []
num_a = 0
num_b = 0
turn_t = 0
case_num = 0
for line in in_file :
	if mode == 0 :
		total_num = int(line)
		print 'total : ' + str(total_num)
		mode = 1
	elif mode == 1 : 
		case_num += 1
		#print 'case:',case_num
		turn_t = int(line) 
		tt = []
		mode = 2
	elif mode == 2 :
		data = line.split(' ')
		num_a = int( data[0] )
		num_b = int( data[1] )
		num_total = num_a + num_b
		mode = 3
	elif mode == 3 :
		s, e = get_time( line )
		e += turn_t
		if num_total > num_b : 
			tt.append( [s,e,0,1] )
		else :
			tt.append( [s,e,0,2] )
			
		num_total -= 1
		if num_total == 0 :
			if total_num != case_num :	mode = 1
			else : mode = 4
			a, b = solve()
			out =  'Case #' + str(case_num)
			out += ': ' + str(a) + ' ' + str(b) + '\n'
			out_file.write( out )
			print out
	else :
		print 'error unexpected case'
	

in_file.close()
out_file.close()
#print convert("112", "012" , "0123")

ps_time = time.time() - ps_time
print ps_time