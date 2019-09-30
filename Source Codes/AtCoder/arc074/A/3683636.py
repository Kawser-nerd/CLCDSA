h, w = list(map(int, input().split()))


if not (h%3)*(w%3):
    print(0)
    exit()

def calc_T(h, w):
    bars = []
    first_cut = w//3 + w%3 - 1
    bars.append(first_cut*h)
    bars.append((h//2)*(w-first_cut))
    bars.append(h*w-sum(bars))
    return max(bars) - min(bars)

print(min(calc_T(h,w), calc_T(w,h), h, w))