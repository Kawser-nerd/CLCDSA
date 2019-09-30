import string

alp = string.ascii_lowercase

def main():
    s = input()
    if len(s) < 26:
        for i in alp:
            if i not in s:
                print (s + i)
                return
    if s == alp[::-1]:
        print(-1)
        return
    L = len(s)
    tmp = []
    tt = ''
    for i, ss in enumerate( s ):
        tmp += [ s[L-i-1] ]
        if s[L-i-1] > s[L-i-2]:
            ans = s[:L-i-2]
            tt = s[L-i-2] 
            break
    tmp.sort()
    for i in tmp:
        if i > tt:
            print (ans + i)
            break
main()