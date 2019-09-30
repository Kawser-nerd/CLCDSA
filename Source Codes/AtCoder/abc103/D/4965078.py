islands, requests = map(int, input().split(" "))
req = []
for r in range(requests):
    a, b = map(int, input().split(" "))
    req.append([a, b])
req = sorted(req, key = lambda x:x[1])
answer = 1
temp_end = req[0][1]
for r in req:
    if r[0] >= temp_end:
        temp_end = r[1]
        answer += 1
print(answer)