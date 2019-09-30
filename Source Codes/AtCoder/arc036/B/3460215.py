# -*- coding: utf-8 -*-
# ??????

S = int(input())
stu = []
zyousyou = 1
kakou = 0
u = 1
s = 1
ans = 1
for i in range(S):
	a = int(input())
	if(i > 0):
		u += 1
		if(a > ba):
			if(kakou == 1):
				if(ans < u-s):
					ans = u-s
				s = i
				kakou = 0
				zyousyou = 1
		elif(a < ba):
			if(zyousyou == 1):
				kakou = 1
				zyousyou = 0
				
	ba = a	
	
if(ans < u-s+1):
	ans = u-s+1
print(ans)