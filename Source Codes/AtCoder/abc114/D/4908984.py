N = int(input())
e = [0] * (N+1)
for i in range(2, N+1):
    cur = i
    for j in range(2, i+1):
        while cur % j == 0:
            e[j] += 1
            cur //= j
def num(m): # e ?????? m-1 ????????
    return len(list(filter(lambda x: x >= m-1, e)))
print(num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1)
    + num(5) * (num(5) - 1) * (num(3) - 2) // 2)