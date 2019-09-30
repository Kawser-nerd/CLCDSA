def b_music(N, Music):
    import re

    def rotate_counterclockwise(matrix):
        return [''.join(s) for s in list(map(list, zip(*matrix)))[::-1]]

    # ?????????????????????????
    music_rotate = rotate_counterclockwise(Music)
    ans = 0
    for row in music_rotate:
        ans += row.count('x')
        row = re.split('[.x]', row)  # ????'o'?????(???????????????)
        for element in row:
            if element:
                ans += 1
    return ans

N = int(input())
Music = [input() for _ in range(N)]
print(b_music(N, Music))