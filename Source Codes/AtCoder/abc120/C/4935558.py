s = input()
a = 0
b = 0
for i in range(len(s)):
    if(s[i] == "0"):
        a += 1
    else:
        b += 1
print(len(s) - abs(a - b))