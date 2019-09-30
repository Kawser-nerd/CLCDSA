def main():
    buf = input()
    S = buf
    K = len(S) // 2
    center_char = S[K]
    while K < len(S):
        if S[K] == center_char and S[-K - 1] == center_char:
            K += 1
        else:
            break
    print(K)

if __name__ == '__main__':
    main()