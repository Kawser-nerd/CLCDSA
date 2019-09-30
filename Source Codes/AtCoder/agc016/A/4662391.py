s = input()
ans = 10**5
def f(s,w):
    cnt = 0
    k = s.count(w)
    length = len(s)
    while True:
        if k==length:
            break
        s_=''
        for i in range(len(s)-1):
            if s[i+1]==w:
                s_+=w
            else:
                s_+=s[i]
        length-=1
        k = s_.count(w)
        s = s_
        cnt+=1
    return cnt
for s_ in s:
    ans = min(ans,f(s,s_))
print(ans)