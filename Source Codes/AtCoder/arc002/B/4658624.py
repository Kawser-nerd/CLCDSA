Y, M, D = [int(_) for _ in input().split("/")]

def is_leap_year(Y):
    if Y % 400 == 0:
        return True
    if Y % 100 == 0:
        return False
    if Y % 4 == 0:
        return True
    return False

day_of_month = [0, 31, 28 + is_leap_year(Y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

while 1:
    if Y % M == 0 and Y // M % D == 0:
        break
    D += 1
    if D > day_of_month[M]:
        M += 1
        D = 1
    if M > 12:
        M = 1
        Y += 1

print("%02d/%02d/%02d" % (Y, M, D))