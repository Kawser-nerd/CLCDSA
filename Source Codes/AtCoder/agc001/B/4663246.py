"""B - Mysterious Light"""
N,X=(int(i) for i in input().split())
def MysteriousLight(tmp,rem):
    while rem:
        tmp, rem= rem,tmp%rem
    return tmp

print(3*(N-MysteriousLight(N,X)))