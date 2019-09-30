N = int(input())
RH = [[int(_) - 1 for _ in input().split()] for _ in range(N)]
GCP_all = [[0, 0, 0] for _ in range(100000)]
Rate_all = [0 for _ in range(100000)]
for i in range(N):
    rate, hand = RH[i]
    GCP_all[rate][hand] += 1
for rate in range(1, 100000):
    Rate_all[rate] = Rate_all[rate - 1] + GCP_all[rate - 1][0] + GCP_all[rate - 1][1] + GCP_all[rate - 1][2]
for i in range(N):
    rate, hand = RH[i]
    w, d = GCP_all[rate][hand - 2], GCP_all[rate][hand]
    print(
        Rate_all[rate] + w,
        N - (Rate_all[rate] + w) - d,
        d - 1,
    )