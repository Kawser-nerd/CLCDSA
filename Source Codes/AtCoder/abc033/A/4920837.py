def password(N: int)->bool:
    s = set((N//(10**i)) % 10 for i in range(4))
    return len(s) == 1


if __name__ == "__main__":
    N = int(input())
    yes = password(N)
    print('SAME' if yes else 'DIFFERENT')