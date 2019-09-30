#A - White Cells

import numpy as np

H, W = map(int, input().split())
h, w = map(int, input().split())

Orig = np.ones((H, W))
Orig[0:h, :] =0
Orig[:, 0:w ] =0

total = int(np.sum(Orig))
print(total)