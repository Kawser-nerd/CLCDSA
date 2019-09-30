from math import factorial

big = int(1e9)+7
def mod_rev_fact(x):
    return pow(factorial(x), big-2, big)

def mod_combi(n, r):
    return (factorial(n) % big) * (mod_rev_fact(r) * mod_rev_fact(n-r) % big) % big

W, H = map(int, input().split())

print(mod_combi(W+H-2, H-1))