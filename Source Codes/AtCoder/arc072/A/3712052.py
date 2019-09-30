N = int(input())
A = [int(_) for _ in input().split()]

#positive
pos_count = 0
sign = 1
cumsum = 0
for a in A:
    cumsum += a
    if cumsum * sign <= 0:
        pos_count += abs(sign - cumsum)
        cumsum = sign
    sign *= -1

#negative
neg_count = 0
sign = -1
cumsum = 0
for a in A:
    cumsum += a
    if cumsum * sign <= 0:
        neg_count += abs(sign - cumsum)
        cumsum = sign
    sign *= -1

print(min(pos_count, neg_count))