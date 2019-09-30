import bisect

n = int(input())
alist = list(sorted(map(int, input().split())))
blist = list(map(int, input().split()))
clist = list(sorted(map(int, input().split())))

ans = 0
for b in blist:
  ai = bisect.bisect_left(alist, b)
  ci = bisect.bisect_right(clist, b)
  if ai == 0 or ci == len(clist):
    continue
  else:
    ans += ai * (len(clist) - ci)
print(ans)