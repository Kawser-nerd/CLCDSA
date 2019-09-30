def manju(A: int, B: int, C: int)->int:
    max_num = 0
    for numA in range(C//A + 1):
        numB = (C - A * numA) // B

        if numB < 0:
            break

        max_num = max(max_num, numA + numB)
    return max_num


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    ans = manju(A, B, C)
    print(ans)