def b_music(N, Music):
    import re

    def rotate_counterclockwise(matrix):
        return [''.join(s) for s in list(map(list, zip(*matrix)))[::-1]]

    # ?????????????????????????
    music_rotate = rotate_counterclockwise(Music)
    ans = 0
    for row in music_rotate:
        row = re.sub(r'o{2,}', 'o', row)  # ????'o'?1?????
        ans += row.count('x') + row.count('o')
    return ans

N = int(input())
Music = [input() for _ in range(N)]
print(b_music(N, Music))