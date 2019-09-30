N, L, T = map(int, input().split())
X = [0 for i in range(N)]
W = [0 for i in range(N)]
E = [0 for i in range(N)]
count = 0
for i in range(N):
    X[i], W[i] = map(int, input().split())
    if W[i] == 1:
        end = X[i] + T
        end = end % L
    if W[i] == 2:
        end = X[i]-T
        end = end % L
        if end < 0:
            end += L
    E[i] = end
    shu = L / 2.0
    if i > 0 and W[i] == 2 and  W[0] == 1:
        sa = X[i] -X[0]
        if sa < 0:
            sa += L
        gikan = sa / 2.0
        count += (T - gikan ) // shu + 1
        if (T - gikan) % shu == 0:
            count -= 1

    if i > 0 and W[i] == 1 and  W[0] == 2:
        sa = X[0] -X[i]
        if sa < 0:
            sa += L
        gikan = sa / 2.0
        count -= (T - gikan ) // shu + 1

#print(E)
count = count % N
if count < 0:
    count += N
count = int(count)
#print(count)
basho = E[0]
E.sort()
ind = E.index(basho)
result = [0 for i in range(N)]
for i in range(N):
    newind = ind + i
    if newind >= N :
        newind -= N
    result[count] = E[newind]
    count += 1
    if count >= N:
        count -= N

for i in range(N):
    print(result[i])