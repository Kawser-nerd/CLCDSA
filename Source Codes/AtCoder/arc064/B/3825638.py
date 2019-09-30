s=list(input())

n=len(s)

if (s[0]==s[n-1] and n%2 ==0) or (s[0] != s[n-1] and n%2 != 0):
    print("First")
else:
    print("Second")