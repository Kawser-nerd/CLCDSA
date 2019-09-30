#????????????

def get_next_int():
    return int(float(input()))
def get_next_ints(delim=" "):
    return tuple([int(float(x)) for x in input().split(delim)])

def get_next_str():
    return input()
def get_next_strs(delim=" "):
    return tuple(input().split(delim))

def get_next_by_types(*value_types,delim=" "):
    return tuple([t(x) for t, x in zip(value_types,input().split(delim))])

def main(print=print):
    n, m, a, b = get_next_ints()  
    
    result = {} 
    
    if n % 2 == 1:
        for j in range(1,m,2):
            if a == 0:
                break
            result[(n, j)] = "<"
            result[(n, j+1)] = ">"
            a -= 1
    
    if m % 2 == 1:
        for i in range(1,n,2):
            if b == 0:
                break
            result[(i, m)] = "^"
            result[(i+1, m)] = "v"
            b -= 1
    if n % 2 == 1 and a % 2 == 1 and m % 2 == 1 and b % 2 == 1:
        #??3x3????????
        result[(n, m-2)] = "<"
        result[(n, m-1)] = ">"
        result[(n-2, m-1)] = "<"
        result[(n-2, m)] = ">"
        result[(n-1, m)] = "^"
        result[(n , m)] = "v"
        result[(n-2, m-2)] = "^"
        result[(n-1 , m-2)] = "v"
        a -= 1
        b -=1
        
    inside_n = n - (n % 2)
    inside_m = m - (m % 2)
    #print("inside=",inside_n,inside_m)
    for i in range(1,inside_n+1,2):
        for j in range(1,inside_m+1,2):
            #print(i,j,a,b)
            if a > 0:
                result[(i, j)] = "<"
                result[(i, j+1)] = ">"
                a -= 1
                if a > 0:
                    result[(i+1, j)] = "<"
                    result[(i+1, j+1)] = ">"
                    a -= 1
            elif b > 0:
                result[(i, j)] = "^"
                result[(i+1, j)] = "v"
                b -= 1
                if b > 0:
                    result[(i, j+1)] = "^"
                    result[(i+1, j+1)] = "v"
                    b -= 1
            else:
                break
        if (a + b) == 0:
            break
    if (a + b) > 0:
        print("NO")
    else:
        print("YES")
        for i in range(1, n+1):
            buffer = []
            for j in range(1, m+1):
                buffer.append(result.get((i,j),"."))
            print("".join(buffer))

if __name__ == '__main__':
    main()