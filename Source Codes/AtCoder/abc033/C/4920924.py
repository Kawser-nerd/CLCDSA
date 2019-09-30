def formula(S: str)->int:
    t = 0           # ??????
    in_mul = False  # ???????
    count = 0       # ????

    for c in S:
        if c == '*':
            in_mul = True
        elif c == '+':
            in_mul = False
        else:
            if in_mul:
                t *= int(c)
            else:
                if t > 0:
                    # ?????????? 0 ?????
                    # ??????????????
                    count += 1

                t = int(c)

    return count + (t > 0)


if __name__ == "__main__":
    S = input()
    ans = formula(S)
    print(ans)