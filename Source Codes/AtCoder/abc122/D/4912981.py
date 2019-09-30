N = int(input())
mod = 1000000007
data = dict([(i+j+k, 1) for i in 'ACGT' for j in 'AGCT' for k in 'ACGT'])
data['AGC'] = 0
data['ACG'] = 0
data['GAC'] = 0
 
def check(text):
    if 'AGC' in text:
        return False
    if 'AGC' in text[1] + text[0] + text[2] + text[3]:
        return False
    if 'AGC' in text[0] + text[2] + text[1] + text[3]:
        return False
    if 'AGC' in text[0] + text[1] + text[3] + text[2]:
        return False
    else:
        return True

for x in range(0,N-3):
    new_data = dict([(i+j+k, 0) for i in 'ACGT' for j in 'AGCT' for k in 'ACGT'])
    for y in data.keys():
        for z in 'ACGT':
            if check(y+z):
                new_data[y[1:]+z] += data[y]%mod
    data = new_data.copy()

print(sum(data.values())%mod)