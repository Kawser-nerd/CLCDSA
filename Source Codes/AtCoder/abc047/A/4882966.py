def fighting_over_candies(a: int, b: int, c: int)->bool:
    return (a + b) == c or (b + c) == a or (c + a) == b


if __name__ == "__main__":
    a, b, c = map(int, input().split())
    yes = fighting_over_candies(a, b, c)
    print('Yes' if yes else 'No')