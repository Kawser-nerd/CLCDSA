A, B, K = map(int, input().split())

List = [x for x in range(min(A,B),0,-1) if A%x ==0 and B%x ==0]
print(List[K-1])