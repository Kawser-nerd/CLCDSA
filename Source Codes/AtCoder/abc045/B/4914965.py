sa = input()
sb = input()
sc = input()
a_idx = 0
b_idx = 0
c_idx = 0
next_ = 'a'
while True:
    if next_ == 'a':
        if a_idx >= len(sa):
            print('A')
            break
        next_ = sa[a_idx]
        a_idx += 1
    elif next_ == 'b':
        if b_idx >= len(sb):
            print('B')
            break
        next_ = sb[b_idx]
        b_idx += 1
    elif next_ == 'c':
        if c_idx >= len(sc):
            print('C')
            break
        next_ = sc[c_idx]
        c_idx += 1