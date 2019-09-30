import numpy as np
field = [list(input().split()) for i in range(4)]
npfield = np.rot90(np.array(field),2)
listfield = npfield.tolist()
print("\n".join([" ".join(map(str, l)) for l in listfield]))