def main():
    N, H = map(int, input().split())

    A = [-1] * N
    B = [-1] * N
    for n in range(N):
        a, b = map(int, input().split())
        A[n] = a
        B[n] = b
    
    B.sort(reverse=True)
    max_A = max(A)
    
    count = 0
    for b in B:
        if max_A < b:
            H -= b
            count += 1
            if H <= 0:
                return count
        else:
            break
    return (H - 1) // max_A + 1 + count

print(main())