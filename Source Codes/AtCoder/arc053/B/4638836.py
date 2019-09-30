from collections import Counter
S=input()
c=Counter(S)
odd_cnt=0
for s in c.values():
    if s%2:
        odd_cnt+=1
if odd_cnt:
    p=(len(S)-odd_cnt)//2
    print((p//odd_cnt)*2+1)
else:
    print(len(S))