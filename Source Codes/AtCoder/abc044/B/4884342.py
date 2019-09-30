def beautiful_strings(w: str) -> bool:
    freq = {}
    for c in w:
        freq.setdefault(c, 0)
        freq[c] += 1
    return all(f % 2 == 0 for f in freq.values())


if __name__ == "__main__":
    w = input()
    yes = beautiful_strings(w)
    print('Yes' if yes else 'No')