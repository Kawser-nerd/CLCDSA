N = int(input())
l = list(map(int,input().split()))
l.sort(reverse=True)
ans = l[1::2]

print(sum(ans[:N]))