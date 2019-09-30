s = int(input())
if s % 4 != 0:
    print("NO")
else:
    if s % 400 == 0:
        print("YES")
    elif s % 100 == 0:
        print("NO")
    else:
        print("YES")