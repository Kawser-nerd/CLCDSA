input()
nbs = map(int, input().split())

answer = 0
count = {}

for nb in nbs:
    count[nb] = count.get(nb, 0) + 1

for nb in sorted(count.keys(), reverse=True):
    searching = (1 << nb.bit_length()) - nb
    nb_count = count[nb]
    sr_count = count.get(searching, 0)
    if sr_count:
        if nb == searching:
            increment = nb_count // 2
        else:
            increment = nb_count if nb_count < sr_count else sr_count
            count[searching] -= increment
        answer += increment

print(answer)