def query(x, y):
    print("? {} {}".format(x, y))
    return int(input())


if __name__ == "__main__":
    N = int(input())
    max_length = 0
    farthest_v = 1

    for i in range(2, N+1):
        dist = query(1, i)
        if max_length < dist:
            max_length = dist
            farthest_v = i

    for i in range(1, N+1):
        if i == farthest_v:
            continue
        max_length = max(max_length, query(farthest_v, i))

    print("!", max_length)