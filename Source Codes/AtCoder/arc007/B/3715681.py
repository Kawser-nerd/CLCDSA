N, M = map(int, input().split())

Ns = [i+1 for i in range(N)]

prev = 0
for m in range(M):
        s = int(input())
        try:
                index = Ns.index(s)
        except ValueError as ex:
                continue
        prev_next = Ns[index]
        Ns[index] = prev
        prev = prev_next
        #print(Ns)

for n in Ns:
        print(n)