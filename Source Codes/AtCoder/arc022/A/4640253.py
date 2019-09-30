s = str(input()).upper()
for i in range(len(s)):
    for j in range(i,len(s)):
        for k in range(j,len(s)):
            if s[i] == "I" and s[j] == "C" and s[k] == "T":
                print("YES")
                exit()
print("NO")