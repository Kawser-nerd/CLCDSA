s = input()
K = int(input())

strs = set()
for k in range(1, K+1):
    for i in range(len(s)+1-k):
        strs.add(s[i:i+k])

print(sorted(list(strs))[K-1])