def count_up(S: str) -> list:
    freq = {c: 0 for c in 'ABCDEF'}
    for c in S:
        freq.setdefault(c, 0)
        freq[c] += 1
    return [v for _, v in sorted(freq.items())]


if __name__ == "__main__":
    S = input()
    ans = count_up(S)
    print(' '.join(map(str, ans)))