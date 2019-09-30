def main():
    C1n = list(map(int, input().split()))
    C2n = list(map(int, input().split()))
    C3n = list(map(int, input().split()))

    C = [C1n, C2n, C3n]

    a_s = [0]
    b_s = [C[0][0], C[0][1],C[0][2]]

    a_s.append(C[1][0] - b_s[0])
    a_s.append(C[2][0] - b_s[0])

    for i, a_i in enumerate(a_s):
        for j, b_j in enumerate(b_s):
            if not ((a_i + b_j) == C[i][j]):
                print("No")
                return 

    print("Yes")
      
main()