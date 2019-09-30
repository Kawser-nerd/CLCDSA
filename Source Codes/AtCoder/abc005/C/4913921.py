import sys
limit = int(input())
int(input())
takoyaki = list(map(int, input().split()))
int(input())
customer = list(map(int, input().split()))

for i in customer:
    index = [j for j in takoyaki if i-limit <= j <= i]
    if len(index) == 0:
        print('no')
        sys.exit()
    takoyaki.remove(index[0])
print('yes')