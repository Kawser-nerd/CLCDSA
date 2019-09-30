def main():
    N = int(input())
    ss = [input().rstrip() for _ in range(N)]
    print("\n".join(sorted(ss, key=(lambda x: x[::-1 ]))))


if __name__ == '__main__':
    main()