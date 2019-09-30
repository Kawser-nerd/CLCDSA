def main():
    q = int(input())
    a = [list(int(i) for i in input().split()) for i in range(q)]
    MAX = 10**5
    is_prime = [1]*MAX
    for i in range(2, MAX):
        if not is_prime[i]:
            continue
        for j in range(i*2, MAX, i):
            is_prime[j] = 0
    s = [0]*MAX
    for i in range(3,MAX):
        s[i] = s[i-1] + 1 if is_prime[i] and is_prime[(i+1)//2] else s[i-1]
    for i in range(q):
        l,r = a[i]
        print(s[r]-s[l-1])

if __name__ == '__main__':
    main()