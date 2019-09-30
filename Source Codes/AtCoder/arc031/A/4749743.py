s=input()
n=len(s)
for i in range(n):
    if s[i]!=s[n-i-1]:
        print("NO")
        break
else:
    print("YES")