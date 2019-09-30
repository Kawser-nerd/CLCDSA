#18
s = input()
x = list()
y = [0]*len(s)

x.append(s[0])
y[0]=1
yk=0
for i in range(1,len(s)):
    if s[i]==s[i-1]:
        y[yk]+=1
    else:
        x.append(s[i])
        yk +=1
        y[yk]+=1

ans = ""
for i in range(len(x)):
    ans += str(x[i]) + str(y[i])
print(ans)