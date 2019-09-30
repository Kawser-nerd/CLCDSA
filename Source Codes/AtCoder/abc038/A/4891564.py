def tea(S: str)->bool:
    return S.endswith('T')


if __name__ == "__main__":
    S = input()
    yes = tea(S)
    print('YES' if yes else 'NO')