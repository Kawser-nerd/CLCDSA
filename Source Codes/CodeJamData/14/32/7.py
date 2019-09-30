#!/usr/bin/python


def cldouble(car,letter):
    ll = "."
    occ = 0
    for c in car:
        if (c==letter) and (c!=ll):
            occ+=1
        ll = c
        
    if occ>1:
        return True
    return False


def clstart(car,letter):
    if car[0] != letter:
        return False
    if car[-1] == letter:
        return False
    return True
    
def clend(car,letter):
    if car[0] == letter:
        return False
    if car[-1] != letter:
        return False
    return True
    
def clmiddle(car,letter):
    if car[0] == letter:
        return False
    if car[-1] == letter:
        return False
    for c in car:
        if c == letter:
            return True
    return False

def clonly(car,letter):
    if car[0] != letter:
        return False
    if car[-1] != letter:
        return False
    return True
    
def fac(n):
    if n==0:
        return 1
    return (n * fac(n-1)) % 1000000007
    
def doit():
    
    
    N = input()
    cars = raw_input().split()
    letters = ('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')
    
    start = {}
    end = {}
    middle = {}
    only = {}
    
    for arr in (start,end,middle,only):
        for letter in letters:
            arr[letter] = 0

    for car in cars:
        for letter in letters:
            if cldouble(car,letter):
                return 0
                
            if clstart(car,letter):
                start[letter] += 1
            if clend(car,letter):
                end[letter] += 1
            if clmiddle(car,letter):
                middle[letter] += 1
            if clonly(car,letter):
                only[letter] += 1
    
    frends = 0
    poss = 1
    for letter in letters:
        if middle[letter]>1:
            return 0
        if middle[letter] == 1:
            if start[letter] > 0:
                return 0
            if end[letter] > 0:
                return 0
            if only[letter] > 0:
                return 0
                
        if start[letter] > 1:
            return 0
        if end[letter] > 1:
            return 0
            
        if start[letter] == 0 and end[letter] == 0 and only[letter]>0:
            frends +=1
        if start[letter] == 1 and end[letter] == 0:
            frends +=1
            
        poss *= fac(only[letter])
    
    if frends == 0:
        return 0    
    poss *= fac(frends)
    
    
    
    return poss % 1000000007


cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    print doit()
