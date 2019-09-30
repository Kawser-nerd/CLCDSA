
# coding: utf-8

# In[1]:

'''
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE

Case #1: CAB
Case #2: MJA
Case #3: OCDE
Case #4: BBAAA
Case #5: CCCABBBAB
Case #6: CCCBAABAB
Case #7: ZXCASDQWE
'''


# In[5]:

Q = int(input())
for q in range(Q):
    s = input()
    ns = s[0]
    for i in range(1, len(s)):
        if s[i] >= ns[0]:
            ns = s[i] + ns
        else:
            ns = ns + s[i]
    print("Case #{}: {}".format(q+1,ns))


# In[ ]:



