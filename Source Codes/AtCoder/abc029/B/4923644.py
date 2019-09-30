def oyster(S: list) -> int:
    return sum('r' in s for s in S)


if __name__ == "__main__":
    S = [input() for _ in range(12)]
    ans = oyster(S)
    print(ans)