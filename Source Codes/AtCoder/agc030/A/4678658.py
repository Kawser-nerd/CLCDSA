A,B,C=[int(i) for i in input().split()]

res = B
if A+B < C:
    res += A+B+1
else:
    res += C

print(res)