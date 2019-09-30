def agent_takahashi(X: int)->int:
    for n in range(400):
        if n * n * n * n == X:
            return n
    return -1


if __name__ == "__main__":
    X = int(input())
    ans = agent_takahashi(X)
    print(ans)