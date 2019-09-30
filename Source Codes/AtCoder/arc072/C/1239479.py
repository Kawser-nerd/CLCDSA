# E
N, D = map(int, input().split())
dv = list(map(int, input().split()))
Q = int(input())
qv = list(map(int, input().split()))

# trace of Alice
dist_alice = D
dist_alice_list = [D]
for i in range(N):
    if dist_alice >= dv[i]:
        dist_alice -= dv[i]
    elif 2*dist_alice >= dv[i]:
        dist_alice = dv[i] - dist_alice
    dist_alice_list.append(dist_alice)

sol_min = [1]
sol_min_ = 1 
for i in range(N-1, -1, -1):
    if 2 * sol_min_ > dv[i]:
        sol_min_ += dv[i]
    sol_min.append(sol_min_)

for i in range(Q):
    if dist_alice_list[qv[i]-1] >= sol_min[N-qv[i]]:
        print("YES")
    else:
        print("NO")