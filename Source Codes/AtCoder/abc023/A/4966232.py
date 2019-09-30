def plus_king(X: int)->int:
    return X//10 + X % 10


if __name__ == "__main__":
    X = int(input())
    ans = plus_king(X)
    print(ans)