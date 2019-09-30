num  = [int(n) for n in input().rstrip().split()]

if num.count(5) == 2 and num.count(7) == 1:
    print("YES")

else:
    print("NO")