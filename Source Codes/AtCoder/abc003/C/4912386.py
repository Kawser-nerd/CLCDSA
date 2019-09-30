Your_rate = 0
N, K = (int(x) for x in input().split())
video_rate = list(map(int, input().split()))
video_rate.sort(reverse=True)
for i in range(K-1, -1, -1):
    Your_rate = (Your_rate + video_rate[i]) / 2
print(Your_rate)