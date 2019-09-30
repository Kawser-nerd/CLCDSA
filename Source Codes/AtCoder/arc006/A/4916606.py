def main():
    ee = list(map(int, input().split()))
    b = int(input())
    ll = list(map(int, input().split()))
    e_counts = [0] * 10
    l_counts = [0] * 10
    for i in range(6):
        e_counts[ee[i]] += 1
        l_counts[ll[i]] += 1
    matches = 0
    for i in range(10):
        k = min(e_counts[i], l_counts[i])
        e_counts[i] -= k
        l_counts[i] -= k
        matches += k
    if matches == 6:
        print(1)
    elif matches == 5:
        if l_counts[b] > 0:
            print(2)
        else:
            print(3)
    elif matches == 4:
        print(4)
    elif matches == 3:
        print(5)
    else:
        print(0)


if __name__ == "__main__":
    main()