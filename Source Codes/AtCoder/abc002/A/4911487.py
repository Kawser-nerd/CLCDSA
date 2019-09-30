def return_max(x, y):
    return x if x > y else y

if __name__ == "__main__":
    x, y, = map(int, input().split())
    print(return_max(x, y))