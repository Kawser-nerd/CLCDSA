import sys
K = int(input())

a = K//50
b = K %50
if K == 0:
    print(2)
    print(0, 0)
    sys.exit()

Ans = [100+a-b]*b + [49+a-b]*(50-b)
print(50)
print(*Ans)