# E
import numpy as np

H, W = map(int, input().split())
S = list()
for _ in range(H):
    S.append(list(input()))
S_arr = np.array(S)

res = "NO"

def check_col_switch(S_arr, H, W):
    if W % 2 == 1:
        res_bar = -1
    else:
        res_bar = 0
    done_col = np.zeros(W)
    for j in range(W):
        if done_col[j] == 1:
            continue
        rev_j = S_arr[::(-1), j]
        for k in range(W):
            if np.prod(S_arr[:, k] == rev_j) == 1 and j != k and done_col[k] == 0:
                done_col[j] = 1
                done_col[k] = 1
                break
        if done_col[j] == 0:
            if np.prod(S_arr[:, j] == rev_j) == 1:
                done_col[j] = 1
                res_bar += 1
            else:
                res_bar += 10
    if res_bar <= 0:
        return "YES"
    else:
        return "NO"
    
def check_col_switch_fast(S_arr, H, W):
    
    col_raw = np.array(["".join(list(S_arr[:, j])) for j in range(W)])
    col_reverse = np.array(["".join(list(S_arr[::(-1), j])) for j in range(W)])
    
    argsa = np.argsort(col_raw)
    argsb = np.argsort(col_reverse)
    
    res = "YES"
    for j in range(W):
        if col_raw[argsa[j]] != col_reverse[argsb[j]]:
            res = "NO"
            break
    cnt_single = 0
    for j in range(W):
        if argsa[j] == argsb[j]:
            cnt_single += 1
    j = 0
    while j < W-1:
        if col_raw[argsa[j]] != col_raw[argsa[j+1]]:
            cnt_single -= 2
            j += 2
        else:
            j += 1
    if cnt_single >= 2:
        res = "NO"
    
    return res
    
def make_pairs(x_list):
    if len(x_list) <= 2:
        return [[x_list]]
    else:
        res = []
        for j in range(1, len(x_list)):
            x_list_s = [x_list[k] for k in range(1, len(x_list)) if k != j]
            res = res + [[[x_list[0], x_list[j]]] + xl for xl in make_pairs(x_list_s)]
        if len(x_list) % 2 == 1:
            x_list_l = [x_list[k] for k in range(1, len(x_list))]
            res = res + [xl + [[x_list[0]]] for xl in make_pairs(x_list_l)]
        return res
    
def run_row_switch(S_arr, row_matching, H, W):
    S_arr_row = S_arr.copy()
    i = 0
    for mat in row_matching:
        if len(mat) == 2:
            S_arr_row[i, :] = S_arr[mat[0], :]
            S_arr_row[H-1-i, :] = S_arr[mat[1], :]
            i += 1
        else:
            S_arr_row[(H-1)//2, :] = S_arr[mat[0], :]
    return S_arr_row
            
row_match_list = make_pairs([i for i in range(H)])


    

# row_matching
same_row_list = []
for i in range(H):
    j_list = [i]
    for j in range(H):
        if i != j and np.prod(np.sort(S_arr[i, :]) == np.sort(S_arr[j, :])) == 1:
            j_list.append(j)
    same_row_list.append(j_list)
    
def pass_condition(rs):
    res = True
    for pair in rs:
        if len(pair) == 1:
            continue
        if pair[1] not in same_row_list[pair[0]]:
            res = False
            break
    return res

row_match_list_s = [rs for rs in row_match_list if pass_condition(rs)]


for rs in row_match_list_s:
    res = check_col_switch(run_row_switch(S_arr, rs, H, W), H, W)
    if res == "YES":
        break
print(res)