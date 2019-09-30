def main():
    buf = input()
    buflist = buf.split()
    N = int(buflist[0])
    T = int(buflist[1])
    buf = input()
    buflist = buf.split()
    A = list(map(int, buflist))
    min_price = A[0]
    max_price_diff = 0
    max_diff_count = 0
    for i in range(1, N):
        if A[i] < min_price:
            min_price = A[i]
        elif A[i] - min_price > max_price_diff:
            max_price_diff = A[i] - min_price
            max_diff_count = 1
        elif A[i] - min_price == max_price_diff:
            max_diff_count += 1
    print(max_diff_count)

if __name__ == '__main__':
    main()