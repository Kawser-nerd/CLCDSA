n, m = map(int, input().split())
requests = []
for i in range(m):
     requests += [list(map(int,input().split()))]

requests = sorted(requests, key=lambda x: x[1])# end <= nextend
start = 0
end = 0
ans = 0
for request in requests:
    nextstart, nextend = request
    if end <= nextstart:
        ans += 1
        start = nextstart
        end = nextend
print(ans)