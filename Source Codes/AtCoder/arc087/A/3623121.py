from collections import defaultdict
def getN():
    return int(input())

def getMN():
    a = input().split()
    b = [int(i) for i in a]
    return b[0],b[1]

def getlist():
    a = input().split()
    b = [int(i) for i in a]
    return b

n = getN()
nums = getlist()

kazu = defaultdict(int)
for i in nums:
    kazu[i] += 1

ans = 0
for x in kazu.keys():
    if kazu[x] >= x:
        ans += kazu[x] - x
    else:
        ans += kazu[x]

print(ans)