s = input()
t = input()
q =int(input())
info = [list(map(int,input().split())) for i in range(q)]
MOD = 3
memo = {"A":1,"B":2}

s_ruiseki = [0]*(len(s)+1)
for i in range(1,len(s)+1):
  s_ruiseki[i] = (s_ruiseki[i-1]+memo[s[i-1]]) % MOD

t_ruiseki = [0]*(len(t)+1)
for i in range(1,len(t)+1):
  t_ruiseki[i] = (t_ruiseki[i-1]+memo[t[i-1]]) % MOD

for i in range(q):
  ans1 =  (2*s_ruiseki[info[i][0]-1] + s_ruiseki[info[i][1]])%MOD
  ans2 =  (2*t_ruiseki[info[i][2]-1] + t_ruiseki[info[i][3]])%MOD
  print("YES" if ans1 == ans2 else "NO")