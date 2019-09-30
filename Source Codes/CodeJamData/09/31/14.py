import operator

ex=execfile
readpath="C:\\Users\\danra\\Downloads\\"
writepath="C:\\Users\\danra\\Downloads\\"

def read1(fn,mode='r'):
    return [x[:-1] for x in file("%s%s" % (readpath,fn),mode).readlines()]

def write1(fn,lines,mode='w'):
    file("%s%s" % (writepath,fn),mode).writelines([x+'\n' for x in lines])

def write2(fn,lines,mode='w'):
    file("%s%s" % (writepath,fn),mode).writelines(["Case #%d: %s\n"%(i+1,x) for (i,x) in enumerate(lines)])

def intersect(sets):
    if len(sets)==0:
        return set()
    res = set(sets[0])
    for x in sets[1:]:
        res.intersection_update(x)
    return res

def union(sets):
    if len(sets)==0:
        return set()
    res = set(sets[0])
    for x in sets[1:]:
        res.update(x)
    return res


def gcd(l):
    if len(l) == 0:
        return None
    if len(l) == 1:
        return l[0]
    if len(l)>=2:
        num1,num2 = l[0],l[1]
        g = gcd2(num1,num2)
        index = 2
        while index < len(l):
            num1 = g
            num2 = l[index]
            g = gcd2(num1,num2)
            index+=1
    return g

def gcd2(num1, num2):
    if num1 > num2:
        for i in range(1,num2+1):
            if num2 % i == 0:
                if num1 % i == 0:
                    result = i
        return result

    elif num2 > num1:
        for i in range(1,num1+1):
            if num1 % i == 0:
                if num2 % i == 0:
                    result = i
        return result

    else:
        result = num1*num2/num1
        return result

def factor(x):
    res=[]
    bound = int(x**0.5)+1
    i=2
    while x>0 and i<=bound:
        if x%i == 0:
            res.append(i)
            x /= i
        else:
            i+=1
    if x>1:
        res.append(x)

    return res

def lcm(l):
    factors = [factor(x) for x in l]
    factorSet = union(factors)
    res = 1
    for x in factorSet:
        maxcount = max([y.count(x) for y in factors])
        res *= x**maxcount
    return res

def toBase(num,base):
    if num == 0:
        return "0"
    res = []
    while num!=0:
        res.append(num % base)
        num /= base
    return "".join(map(str,res[::-1]))


