s = str(input())
key1 = 0
key2 = 0
for i in range(len(s)):
    if s[i] == "I" or s[i] == "i" or key1 == 1:
        key1 = 1
        if s[i] == "C" or s[i] == "c" or key2 == 1:
            key2 = 1
            if s[i] == "T" or s[i] == "t":
                print("YES")
                exit()
print("NO")