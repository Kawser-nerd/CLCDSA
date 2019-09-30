def main():
    a, b = map(int, input().split())
    data = [int(input()) for i in range(a)]
    data.sort()
    ans = data[-1] - data[0]

    for i in range(a - b + 1):
        now_data = data[i + b - 1] - data[i]
        if now_data < ans:
            ans = now_data

    print(ans)



if __name__ == '__main__':
    main()