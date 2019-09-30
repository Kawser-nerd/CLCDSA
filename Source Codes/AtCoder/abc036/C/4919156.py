# def seat_pressure(N: int, A: list)->list:
#     s = set(A)
#     m = {v: i for i, v in enumerate(sorted(set(s)))}
#     return [m[a] for a in A]

N = int(input())
an = [int(input()) for _ in range(N)]

d = {a: i for i, a in enumerate(sorted(set(an)))}

for a in an:
    print(d[a])

# if __name__ == "__main__":
#     N = int(input())
#     A = [input() for _ in range(N)]
#     ans = seat_pressure(N, A)

#     for a in ans:
#         print(a)