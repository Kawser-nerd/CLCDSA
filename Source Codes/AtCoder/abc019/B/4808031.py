s = list(input())
s.append(" ")
i = 0
am = 1
while i < len(s)-1:
    if s[i] == s[i+1]:
        am += 1
    else:
        print(s[i]+str(am), end="")
        am = 1
    i+=1
print()