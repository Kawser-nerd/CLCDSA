Q = int(input())
l_r = [[int(_) for _ in input().split()] for _ in range(Q)]
prime = [False]*(10**5+1)
Csum = [0]*(10**5+1)

for i in range(2, 10**5+1):
    if not prime[i]:
        for j in range(i*2, 10**5+1, i):
            prime[j] = True

cnt = 0
for i in range(3, 10**5+1, 2):
    if (not prime[i]) and (not prime[(i+1)//2]):
        cnt += 1
    Csum[i] = cnt

for i in l_r:
    print(Csum[i[1]]-Csum[i[0]-2])