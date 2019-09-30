s=list(input())
c=0
while len(s)>0:
    p="1"
    q="1"
    r="1"
    if len(s)<5:
        break
    if len(s)<=7:
        if len(s)==5:
            if s==list("dream") or s==list("erase"):
                c=1
                break
        elif len(s)==6:
            if s==list("eraser"):
                c=1
                break
        elif len(s)==7:
            if s==list("dreamer"):
                c=1
                break
    else:
        p=s[len(s)-5:len(s)]
        q=s[len(s)-6:len(s)]
        r=s[len(s)-7:len(s)]
        if p==list("dream") or p==list("erase"):
            del s[len(s)-5:len(s)]
        elif q==list("eraser"):
            del s[len(s)-6:len(s)]
        elif r==list("dreamer"):
            del s[len(s)-7:len(s)]
        else:
            break
print("YES" if c==1 else"NO")