N, M = map(int, input().split())
AB = []

for _ in range(N):
    AB_i = list(map(int, input().split()))
    AB.append(AB_i)
    
AB_sorted = sorted(AB)

num = 0
paied = 0

for AB_i in AB_sorted:
    a = AB_i[0]
    b = AB_i[1]
    
    paied += a * b
    num += b
    
    if num >= M:
        paied -= (num - M) * a
        break

print(paied)