import numpy as np
s = np.array(list(input()))
#B???
ind = np.array(np.where(s=='B'))
#??????
len_ind=ind.shape[1]
#B???
len=s.shape[0]
#B????
dist=np.arange(len-len_ind,len)
#??
ans=np.sum(dist-ind)
print(ans)