def order_of_height(N: int, A: list)->list:
    return [i + 1 for _, i in sorted((-a, i) for i, a in enumerate(A))]


if __name__ == "__main__":
    N = int(input())
    A = [int(s) for s in input().split()]
    ans = order_of_height(N, A)
    for a in ans:
        print(a)