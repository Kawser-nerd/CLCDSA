# ????????????
# ????????any(routes)???????
# ???????????????????????
# ??????????????
from functools import lru_cache

ADJUSTS = [(0, 1), (1, 0), (1, 1)]

H, W = map(int, input().split(" "))
S = [input() for _ in range(H)]

# ???? 
@lru_cache(maxsize=None)
def judge(x, y):
    if (not(0<=x<W and 0<=y<H)) or S[y][x]=="#":
        return True
    return not all(judge(x+ad_x, y+ad_y) for ad_x, ad_y in ADJUSTS)

    # if (not (0<=this_x<W and 0<=this_y<H)) or S[this_y][this_x]=="#":
    #     return False
    # for ad_x, ad_y in ADJUSTS:
    #     x, y = this_x+ad_x, this_y+ad_y
    #     if is_win((x, y)) == False:
    #         return True
    # return False

    # for ad_x, ad_y in ADJUSTS:
    #     x, y = this_x+ad_x, this_y+ad_y
    #     if not(0<=x<W and 0<=y<H):
    #         return False
    #     if S[y][x] == "#":
    #         return False

print("First" if judge(0, 0) else "Second")