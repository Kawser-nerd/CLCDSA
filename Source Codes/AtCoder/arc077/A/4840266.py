n = int(input())
As= list(map(int,input().split()))
back = As[::-2]
if n%2==0:
    forward = As[::2]
else:
    forward = As[1::2]
ans = back+forward
print(" ".join(map(str,ans)))