#AGC007 A
'''
??
?H???W???????
????????????????????????????
??1????????????
????????????????????????????????????????????????
??????????????'#',????????????'.'??????

??
??0,1,...,i,...,H-1????'#'???????????[ai,bi]???????0<=ai<=bi<=W-1
?????0,1,...,j,...,H-2???? b_j == a_(j+1) ??????
'''

import re

H,W = map(int,input().split(' '))
A = []

ans = ''
answers = ('Possible','Impossible')

r = re.compile(r'\.*#+\.*')

for i in range(H):
	s = input()
	if len(r.findall(s)) == 1:
		A.append(s)
	else:
		#'#'?2????????????????????
		ans = answers[1]
		break

if ans == '':
	for i in range(H-1):
		if A[i].rfind('#') == A[i+1].find('#'):
			continue
		else:
			ans = answers[1]
			break

if ans == '':
	ans = answers[0]

print(ans)