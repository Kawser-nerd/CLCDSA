n = int(input())
s = 0
for a_ in range(1, 10):
    for b_ in range(1, 10):
        s += (a_ * b_)
diff = s - n
a = []
for i in range(1, 10):
    if (((diff % i) == 0) & (diff // i <= 9)):
        a.append(str(i) + " x " + str(diff//i))
for a_ in a:
    print(a_)