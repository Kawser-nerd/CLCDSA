A = list(reversed(input()))
B = list(reversed(input()))
C = list(reversed(input()))
 
cards = {'a': A, 'b': B, 'c': C}
 
s = A.pop()
 
while(1):
    try:
        s = cards[s].pop()
    except IndexError:
        print(s.upper())
        exit()