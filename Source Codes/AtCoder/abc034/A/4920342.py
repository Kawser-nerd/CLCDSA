def test(x: int, y: int)->bool:
    return x < y


if __name__ == "__main__":
    x, y = map(int, input().split())
    yes = test(x, y)
    print('Better' if yes else 'Worse')