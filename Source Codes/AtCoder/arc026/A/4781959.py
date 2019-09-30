def main():
    n, a, b = map(int, input().split())
    nb = min(n, 5)
    na = n - nb
    r = b * nb + a * na
    print(r)

main()