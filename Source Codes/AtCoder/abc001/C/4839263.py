import math

def my_round(x, d=0):
    p = 10 ** d
    return float(math.floor((x * p) + math.copysign(0.5, x)))/p

def main(m):
    deg, dis = list(map(int, m.split(' ')))

    ''' dis
    '''
    ddis = my_round(dis/60, 1)
    wind = [0.2, 1.5, 3.3, 5.4, 7.9,
            10.7, 13.8, 17.1, 20.7, 24.4,
            28.4, 32.6]
    w = 12
    for index in range(0, len(wind)):
        if ddis <= wind[index]:
            w = index
            break

    ''' deg
    '''
    if w == 0: return 'C 0'

    word = ['NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW']
    flag = True
    for index in range(0, len(word)):
        if 112.5 + 225 * index <= deg < 112.5 + 225 * (index + 1):
            d = word[index]
            flag = False
            break
    if flag:
        d = 'N'
            
    return '{} {}'.format(d, w)

if __name__ == '__main__':
    try:
        m = input().strip()
        print('{}'.format(main(m)))
    except EOFError:
        pass