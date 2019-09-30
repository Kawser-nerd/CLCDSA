s = input()
t = input()

ans = True
miria = [["@","a"],["@","t"],["@","c"],["@","o"],["@","d"],["@","e"],["@","r"],["a","@"],["t","@"],["c","@"],["o","@"],["d","@"],["e","@"],["r","@"],["@","@"]]
for i in range(0,len(s)):
    if s[i]!=t[i]:
        akagi =[s[i],t[i]]
        #print(akagi)
        if akagi not in miria:
            ans = False
if ans :
    print("You can win")
else:
    print("You will lose")