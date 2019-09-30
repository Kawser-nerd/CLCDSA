def insertion(N: int, S: str)->str:
    bra, ket = 0, 0
    for c in S:
        if c == '(':
            bra += 1
        else:  # c == ')'
            if bra > 0:  # ??????
                bra -= 1
            else:  # ????????
                ket += 1

    ret = ('(' * ket) + S

    bra, ket = 0, 0
    for c in reversed(S):
        if c == ')':
            ket += 1
        else:  # c == '('
            if ket > 0:  # ??????
                ket -= 1
            else:  # ???????
                bra += 1

    ret = ret + (')' * bra)

    return ret


if __name__ == "__main__":
    N = int(input())
    S = input()
    ans = insertion(N, S)
    print(ans)