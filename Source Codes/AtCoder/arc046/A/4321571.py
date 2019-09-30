def a_repdigit(N):
    """
    N???????(??????)??
    """
    s, t = divmod(N - 1, 9)
    ans = str(t + 1) * (s + 1)
    return ans

N = int(input())
print(a_repdigit(N))