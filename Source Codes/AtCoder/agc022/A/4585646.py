S = input()
A = [chr(i) for i in range(ord("a"),ord("z")+1)]

if len(S) < 26 :
    for i in range(len(A)) :
        if A[i] not in S :
            ans = S + A[i]
            break
elif S == "".join(A[::-1]) :
    ans = -1
else :
    B = []
    for i in range(len(A)-1) :
        right = S[len(A)-1-i]
        left = S[len(A)-1-(i+1)]
        B.append(right)
        if left < right:
            last = "z"
            for b in B :
                if left > b :
                    continue
                last = min(last,b)
            ans = S[:len(S)-1-(i+1)] + last
            break
print(ans)