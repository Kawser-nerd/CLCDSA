from collections import deque

MOD = 1000000007

def solve(fs, m):
    queue = deque([(1, 0), (1, fs[0])])
    flavorSet = {0, fs[0]}
    ans = 1
    for f in fs[1:]:
        ans = ans * 2
        if f in flavorSet:
            while f in flavorSet:
                point, f0 = queue.popleft()
                if f0 != f:
                    ans -= point
                else:
                    queue.appendleft((point, 0))
                    flavorSet.add(0)
                flavorSet.remove(f0)
        ans %= MOD
        queue.append((ans, f))
        flavorSet.add(f)
    return ans




if __name__ == "__main__":
    n, m = map(int, input().split())
    fs = [int(input()) for i in range(n)]

    print(solve(fs, m))