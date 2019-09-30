def rect(l1: int, l2: int, l3: int) -> int:
    if l1 == l2:
        return l3
    if l1 == l3:
        return l2
    return l1


if __name__ == "__main__":
    l1, l2, l3 = map(int, input().split())
    ans = rect(l1, l2, l3)
    print(ans)