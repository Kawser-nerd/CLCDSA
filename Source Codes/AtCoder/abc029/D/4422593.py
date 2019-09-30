a = input()
b = int(a)

s = (9-len(a))*'0'+a
ans = 0
for i in range(9):
    if s[i] == '0' and ans==0:
        continue
    ans+=(b//((10**(8-i))*10))*(10**(8-i))
    c = (b%((10**(8-i))*10))+1
    #print(0,c)
    if 2*(10**(8-i))>= c > 10**(8-i):
        ans+=c-10**(8-i)
    elif c>=2*10**((8-i)):
        ans+=10**(8-i)
    #print(ans)
print(ans)