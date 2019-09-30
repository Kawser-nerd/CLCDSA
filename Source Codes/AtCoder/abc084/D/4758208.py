def prime(i):
    if i == 2:
        return True
    else:
        if i % 2 == 0:
            return False
        for j in range(3, int(i**0.5)+1, 2):
            if i % j == 0:
                return False
        return True

Q = int(input())
l_r = [[int(_) for _ in input().split()] for _ in range(Q)]
Csum = [0]*(10**5+1)
cnt = 0

for i in range(3, 10**5, 2):
    if prime(i) and prime((i+1)//2):
        cnt += 1
    Csum[i] = cnt

for i in l_r:
    print(Csum[i[1]]-Csum[i[0]-2])