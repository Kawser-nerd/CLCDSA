S = str(input())
list = []
for i in range(len(S)):
    #print(ord(S[i]))
    if ord(S[i]) >= 48 and ord(S[i]) <= 57:
        list.append(S[i])

if list[0] == "0":
    list.pop(0)
#print(list)

ans = ""
for i in range(len(list)):
    ans += list[i]
print(ans)