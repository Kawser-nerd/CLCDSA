N = int(input())
 
prev = 0
ans = 0
able = True
for i in range(N):
	now = int(input())
	
	if now - prev > 1 or (i == 0 and now != 0):
		print(-1)
		able = False
		break
	elif now - prev == 1:
		ans += 1
	elif now:
		ans += now
	prev = now

if able:
	print(ans)