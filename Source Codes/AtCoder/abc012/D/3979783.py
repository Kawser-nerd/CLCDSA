def warshall_floyd(v_count: int, matrix: list) -> list:
    """ ?????????
    :param v_count: ???
    :param matrix: ????(?????float("inf"))
    """
    # ?????float("inf")????????????????????
    # inf > inf+(-1) ????????????????????????
    for i in range(v_count):
        for j, c2 in enumerate(row[i] for row in matrix):
            for k, (c1, c3) in enumerate(zip(matrix[j], matrix[i])):
                if c1 > c2+c3:
                    matrix[j][k] = c2+c3
    return matrix


if __name__ == "__main__":
    import sys
    N, M = map(int, input().split())

    inf = float("inf")
    matrix = [[inf]*N for _ in [0]*N]
    for i in range(N):
        matrix[i][i] = 0

    for a, b, t in (map(int, l.split()) for l in sys.stdin):
        matrix[a-1][b-1] = matrix[b-1][a-1] = t

    matrix = warshall_floyd(N, matrix)

    print(min(max(row) for row in matrix))