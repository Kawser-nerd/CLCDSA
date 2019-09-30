n = int(input())
b = [int(input())-1 for i in range(n-1)]

mat = [[0 for i in range(n)] for j in range(n)]
for idx, x in enumerate(b):
    mat[x][idx+1] = 1

def f(idx):
    if mat[idx].count(1) == 0:
        return 1
    else:
        arr = []
        for i, x in enumerate(mat[idx]):
            if x == 1:
                arr.append(f(i))
        return min(arr) + max(arr) + 1

print(f(0))