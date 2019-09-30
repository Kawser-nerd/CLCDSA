def query(val):
    print ('?', val)
    ans = input()
    if ans == 'Y':
        return True
    return False
LIMIT = 10 ** 9
import sys
if __name__ == "__main__":
    if (query(LIMIT)):
        res = 1
        while (True):
            if(query(2 * res)):
                print ('!', res)
                sys.exit()
            res *= 10
    digit = 10
    res = LIMIT
    while (True):
        if (query(res)):
            break
        res = res // 10
        digit -= 1
    query = 10 ** (digit)
    keta = 0
    while (keta < digit):
        low = query
        high = query * 10
        left = 0
        right = 10
        while (right - left > 1):
            med = (right + left) // 2
            if keta == 0 and med == 0:
                left = med
                continue
            val1 = list(str(low))
            val1[keta] = str(med)
            val1 = int("".join(val1))
            print ("? %d" %(val1))
            ans = input()
            if (ans == "Y"):
                if (keta == digit - 1):
                    query = val1
                right = med
                continue
            else:
                if (keta < digit - 1):
                    query = val1
                left = med
                continue
        keta += 1
    query = query // 10
    print ("! %d" % (query))