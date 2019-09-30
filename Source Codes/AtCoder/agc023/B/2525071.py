import numpy as np
from scipy.ndimage.interpolation import shift as scipy_shift

class shift:
    def __init__(self,a):
        self.arr = a
        self.height = a.shape[0]
        self.width = a.shape[1]
    def shifted(self,down,right):
        temp1 = self.arr[list(np.linspace(-down, -down + self.height - 1, self.height).astype(np.int32) % self.height), :]
        temp2 = temp1[:, list(np.linspace(-right, -right + self.width - 1, self.width).astype(np.int32) % self.width)]
        return temp2
    def shifted_zero(self,down,right):
        index_vertical = np.arange(self.height)
        index_horizontal = np.arange(self.width)
        temp1 = self.arr[list(scipy_shift(index_vertical, down, output = int, mode = 'constant')),:]
        temp2 = temp1[:,list(scipy_shift(index_horizontal, right, output = int, mode = 'constant'))]
        return temp2
    def is_sym(self,down,right):
        temp = self.shifted(down,right)
        delta = temp - temp.T
        return(not (delta*delta).sum())



N = int(input())
array = [list(input()) for i in range(N)]
array_int = np.array([[ord(i) for i in j] for j in array])

if N >= 2:
    count = np.array([shift(array_int).is_sym(0,i)*(N-i) for i in range(N)]).sum() + np.array([shift(array_int).is_sym(i,0)*(N-i) for i in range(1,N)]).sum()
else:
    count =  int(shift(array_int).is_sym(0,0))
print(count)