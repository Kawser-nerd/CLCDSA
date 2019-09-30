def main():
    a = int(input())
    data = [int(input()) for i in range(a)]
    data.sort()
    data[-1] = data[-1] // 2
    print(sum(data))


if __name__ == '__main__':
    main()