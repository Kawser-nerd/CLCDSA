def main():
    N, M = [int(n) for n in input().split()]
    A = [int(n) for n in input().split()]
    B = [0]*(N+1)
    B[0] = 0
    d = {}
    accum = 0
    for i in range(N+1):
        B[i] = accum
        if i != N:
            accum += A[i]
    
    for i, b in enumerate(B):
        x = b % M
        if x in d.keys():
            d[x] += 1
        else:
            d[x] = 1
    # print(B)
    print(sum([i * (i - 1)//2 for i in d.values()]))
        
# import os,sys, time

# current = os.path.abspath(__file__ + "/..")+"/"
# fdr = open(current + "d-case1.txt", "r")
# sys.stdin = fdr
# t = time.time()
# main()
# print(time.time() - t)
if __name__ == "__main__":
    main()