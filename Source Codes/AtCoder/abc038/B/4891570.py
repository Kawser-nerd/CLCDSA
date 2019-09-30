def display(H1: int, W1: int, H2: int, W2: int)->bool:
    return H1 == H2 or H1 == W2 or W1 == H2 or W1 == W2


if __name__ == "__main__":
    H1, W1 = map(int, input().split())
    H2, W2 = map(int, input().split())
    yes = display(H1, W1, H2, W2)
    print('YES' if yes else 'NO')