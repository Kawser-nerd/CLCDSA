from math import ceil

def main():
    N, C, K =list(map(int, input().split()))
    Ts = []
    for _ in range(N):
        Ts.append(int(input()))

    Ts.sort()

    bus_ct = 0
    in_bus = 1
    st = Ts.pop(0) + K
    for Ti in Ts:
        if Ti > st:
            bus_ct += 1
            in_bus = 1
            st = Ti + K
        elif Ti <= st:
            in_bus += 1

        if in_bus > C:
            bus_ct += 1
            in_bus = 1
            st = Ti + K
    
    if in_bus:
        bus_ct += 1
    
    print(bus_ct)

main()