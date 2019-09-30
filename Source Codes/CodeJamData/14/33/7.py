from multiprocessing import Pool
import Queue

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret

#======================== BOF  =============================#

BLACK = 'B'
WHITE = 'W'
ENCLOSED = 'E'
NOT_ENC = 'N'

def solver(data_container):
    n, m, k = data_container.nmk

    def get_status(i, j, bt):
        if (1 << (i * m + j)) & bt:
            return BLACK
        else:
            return WHITE

    def valid_range(i, j):
        return 0 <= i < n and 0 <= j < m


    bt_sz = n * m
    ans = n*m
    ans = k
    for bt in xrange(1<<bt_sz):
        need_black = 0
        bt2 = bt
        while bt2:
            #bt2 -= (bt2 & -bt2)
            bt2 = bt2 & (bt2-1)
            need_black += 1
        if need_black >= ans:
            continue

        q = Queue.Queue()
        for _ in range(n):
            q.put((_, 0))
            q.put((_, m-1))
        for _ in range(m):
            q.put((0, _))
            q.put((n-1, _))

        all_open = set()
        while not q.empty():
            i, j = q.get()
            if not valid_range(i, j):
                continue
            elif (i,j) in all_open:
                continue
            elif get_status(i, j, bt) == BLACK:
                continue
            else:
                all_open.add((i,j))
                i_dels = [ 0, 1, 0,-1]
                j_dels = [ 1, 0,-1, 0]

                for i_del, j_del in zip(i_dels, j_dels):
                    ii, jj = i + i_del, j + j_del
                    if valid_range(ii,jj) and (ii,jj) not in all_open:
                        q.put((ii,jj))

        enclosed_cnt = n * m - len(all_open)
        if enclosed_cnt >= k:
            ans = min(ans, need_black)

    return ans


class DataContainer:
    def __init__(self):
        self.nmk = read_array(int)
        pass # read data

#======================== EOF  =============================#


if __name__ == '__main__':
    NUM_THREAD = 2
    USE_MULTI = True

    T = input()
    input_queue = [DataContainer() for _ in xrange(T)]
    
    if USE_MULTI:
        pool = Pool(NUM_THREAD)
        result = pool.map(solver, input_queue)
    else:
        result = []
        for i in xrange(T):
            result.append(solver(input_queue[i]))

    for i in range(T):
        print 'Case #%d: %s' % (i+1, result[i])
