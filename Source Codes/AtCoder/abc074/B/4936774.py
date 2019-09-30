n = int(input())
k = int(input())
x = [int(i) for i in input().split()]
s = 0
for x_ in x:
    s += (min(x_, abs(k-x_)) * 2)
print(s)