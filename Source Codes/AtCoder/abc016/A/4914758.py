s = input().split()
A = int(s[0])
B = int(s[1])
if A % B == 0:
    print("YES")
elif A % B != 0:
    print("NO")