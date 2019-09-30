def SI(): return input()
def II(): return int(SI())
def STI(): return SI().split()
def ITI(): return map(int, STI())
def SLI(): return list(SI())
def ILI(): return list(ITI())


A, B = ITI()


def cum_xor(n):
    result = (n + 1) // 2 % 2
    if (n + 1) % 2 == 1: result ^= n

    return result


print(cum_xor(A - 1) ^ cum_xor(B))