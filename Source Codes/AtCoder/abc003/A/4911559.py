def calc(n):
    sum = (n * (n+1) / 2) * 10000
    return (int)(sum / n)

if __name__ == "__main__":
    n, = map(int, input().split())
    print(calc(n))