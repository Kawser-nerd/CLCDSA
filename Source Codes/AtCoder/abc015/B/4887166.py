N = int(input())
soft = list(map(int, input().split()))
while (True):
    try:
        soft.remove(0)
    except:
        break
print(-(-sum(soft)//len(soft)))