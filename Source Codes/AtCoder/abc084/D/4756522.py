Q = int(input())
import math
le = [0]*Q
for i in range(Q):
    le[i]=list(map(int, input().split()))

# print(le)
def is_prime(n):
    if n <= 1: return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False

    return True





list2017 = [0]*(10**5+1)
sum = 0
for i in range(0,10**5+1):
    if is_prime(i) and is_prime((i+1)//2) and i%2!=0:
        sum += 1
    list2017[i]=sum 
        


# print(list2017[:10])

for i in range(Q):
    print(list2017[le[i][1]]-list2017[le[i][0]-1])