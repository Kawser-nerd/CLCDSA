N, K = map(int, input().split())
Items = [list(map(int, input().split())) for i in range(N)]

OK, NG = 0, 100
for i in range(100):
    X = (OK + NG) / 2
    X_list = sorted([w * (p - X) for w, p in Items], reverse=True)
    if sum(X_list[:K]) >= 0:
        OK = X
    else:
        NG = X

print(OK)