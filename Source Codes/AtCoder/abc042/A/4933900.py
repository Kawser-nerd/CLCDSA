A = list(map(int, input().split()))

if A.count(5) == 2 and A.count(7) == 1:
    print("YES")
else:
    print("NO")