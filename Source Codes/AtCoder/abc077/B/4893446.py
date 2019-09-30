N = int(input().strip())

for i in range(N,0,-1):
    kai = int(pow(i,0.5))
    if i == kai * kai:
        print(i)
        exit()