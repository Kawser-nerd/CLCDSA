def main():
    C1n = list(map(int, input().split()))
    C2n = list(map(int, input().split()))
    C3n = list(map(int, input().split()))

    C = [C1n, C2n, C3n]

    for i in range(3):
        for j in range(3):
            if (not (C[i][j] - C[(i+1)%2][j]) == (C[i][(j+1)%2] - C[(i+1)%2][(j+1)%2])) or (not (C[i][j] - C[i][(j+1)%2]) == (C[(i+1)%2][j] - C[(i+1)%2][(j+1)%2])):
                print("No")
                return

    print("Yes")

main()