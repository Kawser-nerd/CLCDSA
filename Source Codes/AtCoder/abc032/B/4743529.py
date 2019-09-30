s = input()
n = int(input())

l = len(s)

ans = []

for i in range(l-n+1):
    ans.append(s[i:i+n])
        
print(len(list(set(ans))))