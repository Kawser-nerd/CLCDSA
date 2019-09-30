s = input()
ans = []
for i in range(len(s) - 2):
    ans.append(abs(int(s[i:i+3]) - 753))
print(min(ans))