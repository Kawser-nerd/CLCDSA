def fuko(deg):
    d = deg / 10
    if d < 11.25 or d >= 348.75:
        return 'N'
    for c in [(33.75, 'NNE'),
              (56.25, 'NE'),
              (78.75, 'ENE'),
              (101.25, 'E'),
              (123.75, 'ESE'),
              (146.25, 'SE'),
              (168.75, 'SSE'),
              (191.25, 'S'),
              (213.75, 'SSW'),
              (236.25, 'SW'),
              (258.75, 'WSW'),
              (281.25, 'W'),
              (303.75, 'WNW'),
              (326.25, 'NW'),
              (348.75, 'NNW')]:
        if d < c[0]:
            return c[1]


def furyoku(dis):
    for c in [(0.2, '0'),
              (1.5, '1'),
              (3.3, '2'),
              (5.4, '3'),
              (7.9, '4'),
              (10.7, '5'),
              (13.8, '6'),
              (17.1, '7'),
              (20.7, '8'),
              (24.4, '9'),
              (28.4, '10'),
              (32.6, '11')]:
        if dis <= c[0]:
            return c[1]
    return '12'


deg, dis = map(int, input().split())
dis = round(dis / 60 + 1e-7, 1)
fk = fuko(deg)
fr = furyoku(dis)
if fr == '0':
    print('C {}'.format(fr))
else:
    print('{} {}'.format(fk, fr))