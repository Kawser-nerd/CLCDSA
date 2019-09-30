S = input()
T = input()
check = True
atto = ["a","t","c","o","d","e","r","@"]
for s,t in zip(S,T):
    if s=="@" and t in atto:
        continue
    elif t=="@" and s in atto:
        continue
    elif s==t:
        continue
    else:
        check = False
        break
if check ==True:
    print("You can win")
else:
    print("You will lose")