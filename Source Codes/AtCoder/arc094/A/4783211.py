A, B, C = map(int, input().split())
wa = A+B+C
maxnum = max(A, B, C)

if wa % 2 == maxnum % 2:
    print((3*maxnum-wa)//2)
else:
    print((3*(maxnum+1)-wa)//2)