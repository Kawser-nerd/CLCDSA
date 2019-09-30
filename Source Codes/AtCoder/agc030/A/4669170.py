def main():
    A, B, C = map(int, input().split())

    if B <= C:
        count = 0

        count += B * 2
        C -= B

        if C >= 1:
            count += 1
            C -= 1

        if A < C:
            count += A
        else:
            count += C

        print(count)
    else:
        print(B+C)


main()