# Python 3.2

from common import *

count1 = [0] * 150
count3 = [0] * 150
count4 = [0] * 150
count6 = [0] * 150
count12 = [0] * 150

count1[0] = 1
count1[2] = 1

M = 1000000007

for i in range(101):
    # row of 2s
    count1[i + 3] = (count1[i + 3] + count1[i]) % M
    count3[i + 3] = (count3[i + 3] + count3[i]) % M
    count4[i + 3] = (count4[i + 3] + count4[i]) % M
    count6[i + 3] = (count6[i + 3] + count6[i]) % M
    count12[i + 3] = (count12[i + 3] + count12[i]) % M

    # row of (1 1) (2 2) (2 2)
    count3[i + 4] = (count3[i + 4] + 3 * count3[i] + 3 * count1[i]) % M
    count6[i + 4] = (count6[i + 4] + 3 * count6[i]) % M
    count12[i + 4] = (count12[i + 4] + 3 * count4[i] + 3 * count12[i]) % M

    # row of (1 2) (1 2) (2 2) (2 1) (2 1) (2 2)
    count6[i + 4] = (count6[i + 4] + 6 * count1[i] + 6 * count3[i] + 6 * count6[i]) % M
    count12[i + 4] = (count12[i + 4] + 6 * count4[i] + 6 * count12[i]) % M

    # row of (2 2 2) (2 1 1) (2 2 2) (1 1 2)
    count4[i + 5] = (count4[i + 5] + 4 * count1[i] + 4 * count4[i]) % M
    count12[i + 5] = (count12[i + 5] + 4 * count3[i] + 4 * count6[i] + 4 * count12[i]) % M

def main(casenum):
    r, c = readints()

    count = count1[r] + count1[r + 2]
    if (c % 3) == 0:
        count += (count3[r] + count3[r + 2]) // 3
    if (c % 4) == 0:
        count += (count4[r] + count4[r + 2]) // 4
    if (c % 6) == 0:
        count += (count6[r] + count6[r + 2]) // 6
    if (c % 12) == 0:
        count += (count12[r] + count12[r + 2]) // 12

    count = count % M

    writecase(casenum, count)

run(main)
