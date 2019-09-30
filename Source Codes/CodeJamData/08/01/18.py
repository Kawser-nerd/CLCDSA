import time
engines = {}
queries = []

def solve() :
	global engines, queries
		
	
	for q in queries :
		for k in engines.keys() :
			if k == q :
				engines[k].append(0)
			else :
				engines[k].append( engines[k][-1]+1 )
	
	cur_key = ''
	change_num = 0
	for n in range( len( queries ),0,-1 ):
		max_val = 0
		for k in engines.keys() :
			if engines[k][n] > max_val :
				max_val = engines[k][n]
				max_key = k
			#print engines[k][n],
		#print
		
		if cur_key != '' :
			if engines[cur_key][n] == 0 : 
				change_num += 1
				cur_key = max_key
		else :
			cur_key = max_key
	print engines
	
	return change_num

ps_time = time.time()
#filename = "A-small-attempt2"
filename = "A-large"
#filename = "test"

in_file = file("./"+filename+".in")
out_file = file("./"+filename+".out","w")
case_num = 0
mode = 0

engine_count = 0
query_count = 0
case_num = 0
for line in in_file :
	if mode == 0 :
		total_num = int(line)
		print 'total : ' + str(total_num)
		mode = 1
	elif mode == 1 : 
		case_num += 1
		print 'case:',case_num
		engines = {}
		engine_count = int(line) 
		mode = 2
	elif mode == 2 :
		engines[line] = [0]
		engine_count -= 1
		if engine_count == 0 : mode = 3
	elif mode == 3 :
		queries = []
		query_count = int(line)
		if query_count == 0 :
			if total_num != case_num :	mode = 1
			else : mode = 5
			out =  'Case #' + str(case_num)
			out += ': ' + str( solve() ) + '\n'
			out_file.write( out )
			print out
		else : mode = 4
	elif mode == 4 :
		
		queries.append(line)
		query_count -= 1
		if query_count == 0 :
			if total_num != case_num :	mode = 1
			else : mode = 5
			
			out =  'Case #' + str(case_num)
			out += ': ' + str( solve() ) + '\n'
			out_file.write( out )
			print out
	else :
		print 'error unexpected case'
	

in_file.close()
out_file.close()
#print convert("112", "012" , "0123")

ps_time = time.time() - ps_time
print ps_time