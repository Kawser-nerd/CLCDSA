N = int(input())
NG_1 = int(input())
NG_2 = int(input())
NG_3 = int(input())
NG = [NG_1,NG_2,NG_3]

for i in range(100):
    if N in NG:
        break
    N -= 3
    if N in NG:
        N += 1
        if N in NG:
            N += 1
            

if N < 1:
    print("YES")
else:
    print("NO")