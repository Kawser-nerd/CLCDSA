N = int(input())

paper = set()
for i in range(N):
    A = int(input())
    if A not in paper:
        paper.add(A)
    else:
        paper.remove(A)

print(len(paper))