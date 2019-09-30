if __name__ == '__main__':

    r = int(input())
    
    s1 = r * r
    s2 = (r + 1) * (r + 1)
    
    ans = s1
    p = 100
    while p < s2:
        s = ((s1 - 1) // p + 1) * p
        if s < s2:
            ans = (s1 - 1) // p + 1
            p = p * 100
        else:
            break
    
    print(ans)