N = int(input())
S = input()
MOD = 10**9+7

alp = 'abcdefghijklmnopqrstuvwxyz'
count_alp = [0 for i in range(26)]
count = 1

for s in S:
    count_alp[alp.find(s)]+=1

for i in count_alp:
    count*= (i+1)
print((count-1)%MOD)