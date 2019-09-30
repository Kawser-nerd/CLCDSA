def main(l):
    counts = {}
    answer = 0
    for nb in l:
        counts[nb] = counts.get(nb, 0) + 1
    for a in sorted(counts.keys(), reverse=True):
        b = (1 << a.bit_length()) - a
        c_a = counts[a]
        c_b = counts.get(b)
        if c_b:
            if a == b:
                answer += c_a // 2
            else:
                increment = c_a if c_a < c_b else c_b
                counts[a] -= increment
                counts[b] -= increment
                answer += increment

    return answer


if __name__ == '__main__':
    input()
    print(main(map(int, input().split())))