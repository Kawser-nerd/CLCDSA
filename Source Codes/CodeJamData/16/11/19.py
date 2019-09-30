
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

for case in range(int(input())):
    s=input().strip()
    ans=[s[0]]
    for ch in s[1:]:
        if ch>=ans[0]: ans.insert(0,ch)
        else: ans.append(ch)
    print("Case #%s: %s"%(case+1,"".join(ans)))
