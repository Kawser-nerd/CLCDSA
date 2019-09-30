def main():
    n, m = [int(i) for i in input().split()]
    ans = [0 for i in range(m+1)]
    for i in range(n):
        k, *a = [int(i) for i in input().split()]
        for j in range(k):
            ans[a[j]] += 1
    print(ans.count(n))
main()