import collections
n=int(input())
S=[ collections.Counter(sorted(list(input()))) for i in range(n) ]
chars=[ chr(i) for i in range(97,97+26) ]
nums=[ min( [S[i][char] for i in range(n)] ) for char in chars ]
ans=''.join([ chars[i]*nums[i] for i in range(26)])
print(ans)