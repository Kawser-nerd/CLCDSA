S = str(input())

def checker(y, m, d):
    if y < 2019: return 'Heisei'
    if y > 2019: return 'Heisei'
    if m  in [1, 2, 3, 4]: return 'Heisei'
    
    return 'TBD'

y, m, d = map(int, S.split('/'))
print(checker(y, m, d))