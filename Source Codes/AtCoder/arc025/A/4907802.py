def main():
    dd = list(map(int, input().split()))
    jj = list(map(int, input().split()))
    res = sum(max(d, j) for d, j in zip(dd, jj))
    print(res)


if __name__ == "__main__":
    main()