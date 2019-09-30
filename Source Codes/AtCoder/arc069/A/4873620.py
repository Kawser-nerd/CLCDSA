N,M = map(int,input().split())
S_num = N
cc_num = M//2
if(S_num <= cc_num):
 ans = (S_num+cc_num)//2
else:
 ans = cc_num
print(ans)