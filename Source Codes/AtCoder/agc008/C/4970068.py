# ??
a_I, a_O, a_T, a_J, a_L, a_S, a_Z = map(int, input().split())

# ??????????I, O, J, L???
R = ((a_I % 2 + a_J % 2 + a_L % 2) >= 2) and min(a_I, a_J, a_L) >= 1
ans = a_O + 2 * ((a_I - R) // 2) + 2 * ((a_J - R) // 2) + \
    2 * ((a_L - R) // 2) + 3 * R

# ??
print(ans)