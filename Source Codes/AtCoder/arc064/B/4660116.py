s = input()
n = len(s)

if s[0] == s[n - 1]:
    if n % 2 == 0:
        print("First")
    else:
        print("Second")
else:
    if n % 2 == 0:
        print("Second")
    else:
        print("First")