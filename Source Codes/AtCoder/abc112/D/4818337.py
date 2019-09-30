def main():
    N, M = map(int, input().split())

    for g in range(M//N, 0, -1):
        if M % g == 0:
            print(g)
            return

if __name__ == '__main__':
    main()