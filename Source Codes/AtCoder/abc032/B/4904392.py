s = input()
k = int(input())
if len(s)<k:
    print(0)
    exit()
res = []
for i in range(len(s)-k+1):
    res.append(s[i:i+k])
print(len(set(res)))