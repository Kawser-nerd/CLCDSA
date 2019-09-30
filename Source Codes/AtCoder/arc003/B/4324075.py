N = int(input())

S=[]
for i in range(N):
    s_in = input()
    reversed_s_in = ''.join(list(reversed(s_in)))
    S.append(reversed_s_in)
    
S.sort()

for j in range(N):
    ans_temp = S[j]
    ans = ''.join(list(reversed(ans_temp)))
    print(ans)