def warshall_floyd(v_count: int, matrix: list) -> list:
    """ ?????????
    :param v_count: ???
    :param matrix: ????(?????float("inf"))
    """
    for i in range(v_count):
        for j, c2 in enumerate(row[i] for row in matrix):
            for k, (c1, c3) in enumerate(zip(matrix[j], matrix[i])):
                if c1 > c2+c3:
                    matrix[j][k] = c2+c3
    return matrix


def create_matrix(s, divisors):
    matrix = [[float("inf")]*51 for _ in [0]*51]
    matrix[0][0] = 0
    for i in range(1, 51):
        matrix[i][i] = 0
        for d in divisors:
            matrix[i][i%d] = 1
    return matrix
    

def check(a, b, matrix):
    inf = float("inf")
    return all(matrix[s][t] != inf for s, t in zip(a, b))


if __name__ == "__main__":
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    _set, inf = set(a), float("inf")

    if a == b:
        print(0)
        exit()

    divisors = list(range(1, 50))
    matrix = create_matrix(_set, divisors)
    warshall_floyd(51, matrix)
    if not check(a, b, matrix):
        print(-1)
        exit()
    matrix = None

    for i in range(49, 0, -1):
        divisors.remove(i)
        if not check(a, b, warshall_floyd(51, create_matrix(_set, divisors))):
            divisors.append(i)

    print(sum(2**d for d in divisors))