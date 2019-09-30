a,b=map(int,input().split())
s=input()
print("Yes" if s[:a].isalnum() and s[a]=='-' and s[a+1:].isalnum() else "No")