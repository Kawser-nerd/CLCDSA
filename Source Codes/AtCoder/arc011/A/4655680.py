m,n,firstm = map(int,input().split())
sold = firstm
sell = firstm
rest = 0
while rest+sell >= m:
    z = sell//m * n
    rest += sell%m
    if rest >= m:
        z += rest//m * n
        rest %= m
    sell = z
    sold += sell
print(sold)