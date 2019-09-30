def getNums(As):
    nums = [0] * N
    stack = [(-1, 0)]
    for iA, A in enumerate(As):
        while stack[-1][1] > A:
            stack.pop()
        nums[iA] = iA - stack[-1][0]
        stack.append((iA, A))

    return nums


N = int(input())
As = list(map(int, input().split()))

numLs = getNums(As)
numRs = getNums(reversed(As))
print(sum([A * numL * numR for A, numL, numR in zip(As, numLs, reversed(numRs))]))