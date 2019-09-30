import time	
import math
def fstr( f ) :
	ret = str( int( f ) )
	ret += '.'
	for n in range(6) :
		f*=10
		ret += str( int( f%10 ) )
	return ret
	
def solve(f, R, t, r, g) :
	f = float( f )
	R = float( R )
	t = float( t )
	r = float( r )
	g = float( g )
	
	if g <= f+f :
		return fstr(1)
	inner_area = 0
	bl_x = r+f
	while bl_x < R-t-f :
		tr_x = bl_x-f + g-f
		
		bl_y = r+f
		while bl_y < R-t-f:
			tr_y = bl_y-f +g-f
			inner_area += get_inner_area( bl_x,bl_y,tr_x,tr_y,R-t-f)
			bl_y += g + (2*r)
		bl_x += g + (2*r)
		
	outer_area = (math.pi*(R)*(R))/4
	
	ret = (outer_area-inner_area)/outer_area
	return fstr(ret)

def get_inner_area( bl_x, bl_y, tr_x, tr_y, r ) :
	if r == 0 :
		return 0
	if math.sqrt( tr_x * tr_x + tr_y * tr_y ) <= r :
		x = tr_x - bl_x
		y = tr_y - bl_y
		return x*y
	
	if math.sqrt( bl_x*bl_x + bl_y*bl_y ) >= r :
		return 0
	
	if math.sqrt( bl_x*bl_x + tr_y*tr_y ) <= r :
		if math.sqrt( tr_x*tr_x + bl_y*bl_y) <= r :
			#print '/',
			p1_y = tr_y
			p1_x = math.sqrt( (r*r) - (p1_y * p1_y) )
			
			p2_x = tr_x
			p2_y = math.sqrt( (r*r) - (p2_x * p2_x) )
			x = tr_x - p1_x
			y = tr_y - p2_y
			l = math.sqrt( x*x + y*y ) / 2
			theta = abs( math.asin( l/r ) )
			tri_area = math.cos( theta ) * r * l
			arc_area = theta * r*r	# ==(theta/pi) * (pi*r*r)
			arc_area -= tri_area
			
			tri_area = x*y / 2
			x = tr_x - bl_x
			y = tr_y - bl_y
			rect_area = x*y
			rect_area = rect_area - tri_area + arc_area
		else :			
			#print '-',
			p1_y = tr_y
			p1_x = math.sqrt( (r*r) - ( p1_y * p1_y ) )
			
			p2_y = bl_y
			p2_x = math.sqrt( (r*r) - ( p2_y * p2_y ) )
			x = p2_x - p1_x
			y = tr_y - bl_y
			l = math.sqrt( x*x + y*y ) / 2
			theta = abs( math.asin( l/r ) )
			tri_area = math.cos( theta ) * r * l
			arc_area = theta * r*r	# ==(theta/pi) * (pi*r*r)
			arc_area -= tri_area
			
			tri_area = x*y / 2
			x = p1_x - bl_x
			y = tr_y - bl_y
			rect_area = x*y
			rect_area = rect_area + tri_area + arc_area
	else :
		if math.sqrt( tr_x*tr_x + bl_y*bl_y) >= r :
			#print 'v',
			p1_x = bl_x
			p1_y = math.sqrt( (r*r) - ( p1_x * p1_x ) )
			
			p2_y = bl_y
			p2_x = math.sqrt( (r*r) - ( p2_y * p2_y ) )
			
			x = p2_x - bl_x
			y = p1_y - bl_y
			
			l = math.sqrt( x*x + y*y ) / 2
			theta = abs( math.asin( l/r ) )
			tri_area = math.cos( theta ) * r * l
			arc_area = theta * r*r	# ==(theta/pi) * (pi*r*r)
			arc_area -= tri_area
			
			tri_area = x*y / 2
			rect_area = tri_area + arc_area
		else :
			#print '!',
			p1_x = bl_x
			p1_y = math.sqrt( (r*r) - ( p1_x * p1_x ) )
			
			p2_x = tr_x
			p2_y = math.sqrt( (r*r) - ( p2_x * p2_x ) )
			
			x = tr_x - bl_x
			y = p1_y - p2_y
			
			l = math.sqrt( x*x + y*y ) / 2
			theta = abs( math.asin( l/r ) )
			tri_area = math.cos( theta ) * r * l
			arc_area = theta * r*r	# ==(theta/pi) * (pi*r*r)
			arc_area -= tri_area
			
			tri_area = x*y / 2
			x = tr_x - bl_x
			y = p2_y - bl_y
			rect_area = x*y
			rect_area +=tri_area + arc_area
	
	return rect_area
	
	
# for r in range( 17) :
	# #print get_inner_area(0,1,1,2,(float(r)/10))
# exit()

# inner_area = 0
# g= 1
# R = 10
# bl_x = 0
# x=0;
# y=0
# while bl_x < 10 :
	# tr_x = bl_x + g
	
	# y=0
	# bl_y = 0
	# while bl_y < 10:
		# tr_y = bl_y +g
		# inner_area = get_inner_area( bl_x,bl_y,tr_x,tr_y,R)
		# #print fstr(inner_area),
		# bl_y += g
		# y+=1
	# #print ''
	# bl_x += g
	# x+=1	
# exit(1)
ps_time = time.time()
filename = "C-large"
#filename = "C-small-attempt0"
#filename = "test"

in_file = file("./"+filename+".in")
out_file = file("./"+filename+".out","w")


case_num = 0
for line in in_file :
	if case_num == 0 :
		total_num = int(line)
		print 'total : ' + str(total_num)
	else :
		line = line.replace('\n','')
		data = line.split(' ')
		#print data
		out =  'Case #' + str(case_num)
		out += ': ' + solve( data[0], data[1],data[2],data[3],data[4]) + "\n"
		out_file.write( out )
		print out,
	case_num += 1

in_file.close()
out_file.close()
#print convert("112", "012" , "0123")

ps_time = time.time() - ps_time
#print ps_time