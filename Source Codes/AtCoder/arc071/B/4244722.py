def getN():
    return int(input())

def getMN():
    a = input().split()
    b = [int(i) for i in a]
    return b[0],b[1]

def getlist():
    a = input().split()
    b = [int(i) for i in a]
    return b

MOD = 1000000007

n,m = getMN()
anums = getlist()
bnums = getlist()

#??????x?????????
#x_i * (i-1) - (???)
def calc_accum_width(nums):
    x_pos_acc = 0
    x_width_acc = 0

    for i, a in enumerate(nums):
        x_width_acc += a * i - x_pos_acc
        x_pos_acc += a

    return x_width_acc

x_acc = calc_accum_width(anums)
y_acc = calc_accum_width(bnums)

print(x_acc * y_acc % MOD)