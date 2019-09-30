n = input()
ans = 9*(len(n)-1)
if n[1:]=='9'*(len(n)-1):
    print(ans+int(n[0]))
else:
    print(ans+int(n[0])-1)