if __name__ == '__main__':
    n, k = map(int, input().split())
    trees = [0] * n
    for i in range(n):
        trees[i] = int(input())
    trees.sort()

    ans = 10 ** 9
    for i in range(n - k + 1):
        diff = trees[i + k - 1] - trees[i]
        if diff < ans:
            ans = diff
    print(ans)