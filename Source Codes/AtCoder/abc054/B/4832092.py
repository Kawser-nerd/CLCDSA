def do_match(A: list, B: list, offsets: tuple, size_B: int) -> bool:
    oh, ow = offsets
    for h in range(size_B):
        for w in range(size_B):
            if A[oh + h][ow + w] != B[h][w]:
                return False
    return True


def template_matching(N: int, M: int, A: list, B: list) -> bool:
    for offset_h in range(N - M + 1):
        for offset_w in range(N - M + 1):
            if do_match(A, B, (offset_h, offset_w), M):
                return True
    return False


if __name__ == "__main__":
    N = 0
    M = 0
    N, M = map(int, input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]
    yes = template_matching(N, M, A, B)
    print('Yes' if yes else 'No')