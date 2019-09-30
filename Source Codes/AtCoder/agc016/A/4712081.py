from string import ascii_lowercase
s=input()
ans=100
for c in ascii_lowercase:
    ans=min(ans,max([len(x)for x in s.split(c)]))
print(ans)