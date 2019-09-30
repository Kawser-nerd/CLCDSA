import heapq


def main():
    n = int(input())
    a = list(map(int, input().split()))

    sum_max, sum_min = [0] * (n+1), [0] * (n+1)
    mx_pq, mn_pq = [], []

    for i in range(n):
        heapq.heappush(mx_pq, a[i])
        heapq.heappush(mn_pq, -a[3*n-i-1])

    sum_max[0], sum_min[n] = sum(mx_pq), -sum(mn_pq)

    for i in range(1, n+1):
        if mx_pq[0] < a[n+i-1]:
            sum_max[i] = sum_max[i-1] + a[n+i-1] - heapq.heappop(mx_pq)
            heapq.heappush(mx_pq, a[n+i-1])
        else:
            sum_max[i] = sum_max[i-1]

        if mn_pq[0] < -a[2*n-i]:
            sum_min[n-i] = sum_min[n-i+1] + a[2*n-i] + heapq.heappop(mn_pq)
            heapq.heappush(mn_pq, -a[2*n-i])
        else:
            sum_min[n-i] = sum_min[n-i+1]

    ans = -10 ** 16
    for i in range(n+1):
        ans = max(ans, sum_max[i]-sum_min[i])

    print(ans)


if __name__ == '__main__':
    main()