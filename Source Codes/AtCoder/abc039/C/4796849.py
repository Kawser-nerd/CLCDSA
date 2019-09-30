S = input()
if S[:11] == "WBWBWWBWBWB":
    print('Do')
elif S[:9] == 'WBWWBWBWB':
    print('Re')
elif S[:7] == 'WWBWBWB':
    print('Mi')
elif S[:6] == 'WBWBWB':
    print('Fa')
elif S[:11] == 'WBWBWWBWBWW':
    print('So')
elif S[:9] == 'WBWWBWBWW':
    print('La')
else:
    print('Si')