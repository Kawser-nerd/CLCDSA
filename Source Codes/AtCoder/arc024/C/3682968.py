def solve():
    from collections import deque
    N, K = map(int, input().split())
    S = [10**((ord(c)-97)*5) for c in input()]

    if N//2 < K:
        print("NO")
        exit()

    substring = set()
    dq = deque()
    add, append, popleft = substring.add, dq.append, dq.popleft

    subtotal = sum(S[N-K:])
    append(subtotal)

    for n1, n2 in zip(S[N-K-1:N-2*K:-1], S[::-1]):
        subtotal += n1 - n2
        append(subtotal)

    for n1, n2 in zip(S[N-2*K::-1], S[N-K::-1]):
        add(popleft())
        subtotal += n1 - n2
        if subtotal in substring:
            print("YES")
            exit()
        append(subtotal)
    print("NO")


if __name__ == "__main__":
    solve()