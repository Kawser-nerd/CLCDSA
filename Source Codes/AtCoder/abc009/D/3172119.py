from functools import reduce, partial
from itertools import combinations, product
import numpy as np

e = (1<<32)-1
k, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

mat = [0]*k
mat[0] = reduce(lambda acc,x: (acc<<32)^x, reversed(c))
for i in range(1,k):
    mat[i] ^= e << (i-1)*32

def mat_transpose(mat, k):
    tmat = [0]*k
    for i,j in combinations(range(k), 2):
        tmat[i] ^= mat[j]<<(j-i)*32 & e<<j*32
        tmat[j] ^= mat[i]>>(j-i)*32 & e<<i*32
    for i in range(k):
        tmat[i] ^= mat[i] & e<<i*32
    return tmat

def vec_mul(vec0, vec1, k):
    vec = vec0&vec1
    while k!=1:
        k += 1
        k >>= 1
        vec ^= vec>>k*32
        vec &= (1<<k*32)-1
    return vec

def mat_mul(mat1, mat2, u, v, w):
    tmat2 = mat_transpose(mat2, w)
    ret_mat = []
    tmat2.reverse()
    tmat2 = np.array(tmat2, dtype=object)
    ret_mat_append = ret_mat.append

    for row in mat1:
        vec = np.bitwise_and(row, tmat2)
        k = v
        while k!=1:
            k += 1
            k >>= 1
            vec = np.bitwise_xor(vec, np.right_shift(vec, k*32))
            vec = np.bitwise_and(vec, (1<<k*32)-1)
        ret_mat_append(reduce(lambda acc,x: (acc<<32)^x, vec))

    return ret_mat

def mat_pow(mat, i):
    j = 1
    k = len(mat)
    res = [0 for _ in mat]
    for x in range(k):
        res[x] = (e<<x*32)
    square_mat_mul = partial(mat_mul, u=k, v=k, w=k)
    while j<=i:
        if i&j:
            res = square_mat_mul(res, mat)
        mat = square_mat_mul(mat, mat)
        j <<= 1
    return res

if m<=k:
    print(a[m-1])
else:
    mat_n = mat_pow(mat, m-k)
    res = vec_mul(mat_n[0], reduce(lambda acc,x: (acc<<32)^x, a), k)
    print(res)