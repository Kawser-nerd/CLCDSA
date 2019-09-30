def main():
    N = int(input())
    cs = list(input().rstrip())
    result = {i: 0 for i in range(1, 5)}
    for c in cs:
        c = int(c)
        result[c] += 1

    sorted_result_values = sorted(result.values())
    print("{} {}".format(sorted_result_values[-1], sorted_result_values[0]))


if __name__ == '__main__':
    main()