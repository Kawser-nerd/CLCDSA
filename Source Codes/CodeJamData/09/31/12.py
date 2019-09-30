def get_base(digits):
    return len(set(list(str(digits))))

def minsecond(digits):
    #base = get_base(digits))
    digits = list(digits)
    new_digits = list()
    count = 1
    letter2digit = {}
    tmp = digits.pop(0)
    letter2digit[tmp]=str(count)
    count = 0
    new_digits.append(letter2digit[tmp])
    while digits:
        tmp = digits.pop(0)
        if tmp in letter2digit:
            new_digits.append(letter2digit[tmp])
            
        else:
            if count == 0:
                letter2digit[tmp] = str(count)
                new_digits.append(letter2digit[tmp])
                count = 2
                
            else:
                letter2digit[tmp] = str(count)
                new_digits.append(letter2digit[tmp])
                count += 1
    new_digits = int(''.join(new_digits))
    second = cal_base(new_digits, count)
    return second
    
def cal_base(d, base):
    if base <=1:
        base = 2
    
    d = list(str(d))
    count = 0
    res = 0
    while d:
        t = int(d.pop())
        res += t*base**count
        count += 1
        
    return res
        
        
def main(filename, result='result.txt'):
    rfile = open(filename)
    rfile.readline()
    case = 1
    wfile = open(result, 'w')
    for line in rfile:
        d = line.strip()
        n = minsecond(d)
        wfile.write('Case #'+str(case)+': '+str(n)+'\n')
        case += 1
        print case
        
        
if __name__ == '__main__':
    import sys
    import psyco
    psyco.full()
    in_file = sys.argv[1]
    
    main(in_file)
        
        
        
        
        
        
        
        
        
        
        
        