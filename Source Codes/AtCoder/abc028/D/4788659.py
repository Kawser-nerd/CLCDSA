N, K=list(map(int, input().split()))

answer = ((K-1)*1*(N-K) * 6 + 1*1*(N-K) *3 + (K-1)*1*1 *3 + 1)/ N**3
print(answer)