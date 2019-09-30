from collections import Counter
n=int(input())
counter=Counter(1 if x % 2 else 2 if x % 4 else 4 for x in (int(s) for s in input().split()))
print('Yes' if counter[1] <= counter[4] or counter[2] == 0 and counter[1] == counter[4] + 1 else 'No')