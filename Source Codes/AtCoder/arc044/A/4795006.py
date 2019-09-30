n=int(input())
s=str(n)
ans=True
if n==1:
    ans=False
elif n not in [2,3,5,7]:
    if sum([int(i) for i in s])%3==0 or int(s[-1])%2==0 or s[0]=="5":
        ans=False
print("Prime" if ans else "Not Prime")