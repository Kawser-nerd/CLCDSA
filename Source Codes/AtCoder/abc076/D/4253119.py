#????????????
def calc_area(v_end, v_start, v_max, dt):
    kouten_v = (v_end + v_start + dt) / 2
    kouten_t = kouten_v - v_start
    if 0 < kouten_t < dt:
        area = (v_start + kouten_v) * kouten_t / 2 #??
        area +=  (v_end + kouten_v) * (dt - kouten_t) / 2 #??
        area -=  max(0, (kouten_v - v_max))** 2 #?????
    else:
        area = (v_start + v_end) *  dt / 2
    return area

def main():
    #????????????
    n=int(input())
    t=[int(i) for i in input().split()]
    v=[int(i) for i in input().split()]

    #???????????????
    #??????????-1????????????
    max_velocity = [0]
    for i in range(1, n):
        max_velocity_ = min(v[i-1], v[i], max_velocity[i-1] + t[i-1])
        max_velocity.append(max_velocity_)
    max_velocity.append(0)

    #????????????-1??????????????fitting??
    for i in range(n-1):
        if  max_velocity[-(i+1)] - max_velocity[-(i+2)] < -t[-(i+1)]:
            max_velocity[-(i+2)] = max_velocity[-(i+1)] + t[-(i+1)]

    #?????????????????
    ans = 0
    for i in range(n):
        ans += calc_area(max_velocity[i+1], max_velocity[i], v[i], t[i])
    print(ans)

main()