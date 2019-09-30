R, G, B = map(int, input().split())
ans = 10**10

def prog(n) :
	return n*(n+1)//2

for g_left in range(-49-G, 51) :
	g_right = g_left + G - 1
	
	if -100 + (R-1)//2 < g_left :
		r_left = -100 - R//2
		r_right = r_left + R - 1
	else :
		r_right = g_left - 1
		r_left = r_right - R + 1
		
	if g_right < 100 - (B-1)//2 :
		b_right = 100 + B//2
		b_left = b_right - B + 1
	else :
		b_left = g_right + 1
		b_right = b_left + B - 1
	
	res = 0
	if r_left <= -100 <= r_right :
		res += prog(-100 - r_left)
		res += prog(r_right - (-100))
	else :
		res += prog(R)
		res += R * (-100 - r_right - 1)
		
	if b_left <= 100 <= b_right :
		res += prog(100 - b_left)
		res += prog(b_right - 100)
	else :
		res += prog(B)
		res += B * (b_left - 100 - 1)
		
	if g_left <= 0 <= g_right :
		res += prog(-g_left)
		res += prog(g_right)
	elif g_right < 0 :
		res += prog(G)
		res += G * (-g_right - 1)
	elif 0 < g_left :
		res += prog(G)
		res += G * (g_left - 1)
	
	ans = min(ans, res)
	
print(ans)