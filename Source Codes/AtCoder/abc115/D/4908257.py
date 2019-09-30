N, X = list(map(int, input().split()))

layers={0:1}
def layers_of_level(n):
    if n in layers:
        return layers[n]
    layers[n] = 2*layers_of_level(n-1)+3
    return layers[n]

def how_many_putty(n,x):
    if n==0 and x==1:
        return 1
    if n==layers_of_level(n):
        return 2**(n+1)-1

    total_layers = layers_of_level(n)
    if x==1:
        return 0
    if x <= 1+layers_of_level(n-1):
        return how_many_putty(n-1, x-1)
    if x == 1+layers_of_level(n-1)+1:
        return how_many_putty(n-1, x-2)+1
    if x <= 1+2*layers_of_level(n-1)+1:
        return how_many_putty(n-1,layers_of_level(n-1))+1+ how_many_putty(n-1,x-layers_of_level(n-1)-2)
    else:
        return 2*how_many_putty(n-1,layers_of_level(n-1))+1

print(how_many_putty(N,X))