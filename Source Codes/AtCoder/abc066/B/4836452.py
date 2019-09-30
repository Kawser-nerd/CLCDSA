s=input()
l=len(s)
l -= 1
if l%2>0:
    l -= 1
for i in range(l, 1, -2):
    j=i//2
    if s[0:j] == s[j:j*2]:
        print(i)
        break