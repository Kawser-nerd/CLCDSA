def b_jaccard(Na, Nb, A, B):
    # A, B???????????????????set()????????
    a_set, b_set = set(A), set(B)
    ans = len(a_set & b_set) / len(a_set | b_set)
    ans = round(ans, 9)
    return ans

Na, Nb = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
print(b_jaccard(Na, Nb, A, B))