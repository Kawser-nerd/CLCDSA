import sys 
RESOURCE_DICT = dict([(k,v) for k,v in zip(range(1,10),[2,5,5,4,5,6,3,7,6])])

def get_input():
    N,M = [ int(_) for _ in input().split()]
    A = [int(_) for _ in input().split()]
    return N,M,A


def solve(N,M,A):
    sorted_A = sorted(A)[::-1]
    dp = fill_dp(N,sorted_A)
    array = find_array(dp,N,sorted_A)
    return "".join(map(str,array))

def fill_dp(N,A):
    dp = [ -100*N for _ in range(N+1)]
    dp[0] = 0
    for i in range(1,N+1):
        fill(A,dp,i,N)
    return dp

def fill(A,dp,n,N):
    cand = [ dp[n-RESOURCE_DICT[num]]+1 for num in A if n - RESOURCE_DICT[num] >= 0 ]
    dp[n] = max(cand) if len(cand) > 0  else -100*N

def find_array(dp,N,sorted_A):
    array = []
    current_n = N
    for _ in range(dp[N]):
        for number in sorted_A:
            if current_n-RESOURCE_DICT[number] >= 0  and dp[current_n-RESOURCE_DICT[number]] == dp[current_n]-1:
                array.append(number)
                current_n -= RESOURCE_DICT[number]
                break
    return array


if __name__ =="__main__":
    N,M,A = get_input()
    ans = solve(N,M,A)
    print(ans)