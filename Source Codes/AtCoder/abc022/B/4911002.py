N = int(input())
res = 0
x = [0]*10**5
for _ in range(N):
    x[int(input())-1] += 1
print(sum(x) - sum([1 if _ != 0 else 0 for _ in x]))