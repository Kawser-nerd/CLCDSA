s = input()
sub = 1000000
for i in range(len(s) - 2):
    i = abs(int(s[i:i+3]) - 753)
    if i < sub:
        sub = i
print(sub)