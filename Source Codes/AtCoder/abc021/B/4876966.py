N = int(input())
a,b = map(int,input().split())
K = int(input())
Ps = list(map(int,input().split()))
Ps.append(a)
Ps.append(b)
if len(Ps)==len(set(Ps)):
    print("YES")
else:
    print("NO")