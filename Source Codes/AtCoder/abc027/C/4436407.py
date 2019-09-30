N = int(input())

depth = 0

while 2**depth <= N:
    depth += 1

if depth % 2 == 0:
    def takahashi(x): return 2 * x

    def aoki(x): return 2 * x + 1
else:
    def takahashi(x): return 2 * x + 1

    def aoki(x): return 2 * x

x = 1
t_turn = True
while x <= N:
    if t_turn:
        x = takahashi(x)
    else:
        x = aoki(x)
    t_turn = not t_turn

print("Takahashi" if t_turn else "Aoki")