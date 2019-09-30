A, B = map(int, input().split())
S = list(input())
suji = [str(i) for i in range(0, 10)]
try:
    a = int("".join(S[:A]))
    b = int("".join(S[B:]))
    if (S[A] in suji):
        print("No")
    else:
        print("Yes")
except:
    print("No")