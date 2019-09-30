"""
agc
acg
gac
axgc
agxc
"""

n = int(input())
MOD = 10**9 + 7
dpa = [0, 0, 1]
dpc = [0, 0, 1]
dpg = [0, 0, 1]
dpt = [0, 0, 1]

for i in range(2, n+2):
    dpa.append(dpa[i] + dpc[i] + dpg[i] + dpt[i])
    dpc.append(dpa[i]-dpg[i-1] + dpc[i] + dpg[i]-dpa[i-1]-2*dpa[i-2] + dpt[i]-dpa[i-2])
    dpg.append(dpa[i] + dpc[i]-dpa[i-1]+dpg[i-2] + dpg[i] + dpt[i])
    dpt.append(dpa[i] + dpc[i] + dpg[i] + dpt[i])
    
print((dpa[n+1]+dpg[n+1]+dpc[n+1]+dpt[n+1]) % MOD)