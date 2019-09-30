# AC
import math

D, G = map(int, input().split())
p_c_list = [list(map(int, input().split())) for _ in range(D)]

min_n_solved = 1000000000
for p_combi in range(1 << D):
    tmp_score = 0
    n_solved = 0
    selected_p_idxs = []  # Selected indexes of problems
    for digit in range(D):
        if (p_combi >> digit) & 1:
            # p_i: p_c_list[digit][0]
            # c_i: p_c_list[digit][1]
            tmp_score += \
                100 * (digit+1) * p_c_list[digit][0] + p_c_list[digit][1]
            n_solved += p_c_list[digit][0]
            selected_p_idxs.append(digit)
    score_diff = tmp_score - G
    # print('1:', n_solved, 'score_diff:', score_diff)
    if score_diff >= 0:
        # Fine-tuning to reduce "n_solved" problems over solved
        # "selected_p_idxs" were already sorted by probrems
        # from low points to high
        p_idx_lowest = selected_p_idxs[0]
        score_per_p = 100 * (p_idx_lowest + 1)
        # if score_diff - bonus_point > 0
        n_oversolved = None
        score_diff_wo_bonus = score_diff - p_c_list[p_idx_lowest][1]
        if score_diff_wo_bonus > 0:
            n_oversolved = round(score_diff_wo_bonus / score_per_p)
            if n_oversolved < p_c_list[p_idx_lowest][0]:
                n_solved -= n_oversolved
        # print('2:', n_solved)
    else:
        not_selected_p_idxs = \
            [p_idx for p_idx in range(D) if p_idx not in selected_p_idxs]
        not_selected_p_idxs = sorted(not_selected_p_idxs, reverse=True)
        # Select a problem index
        # which have highest point in not_selected_p_idxes
        not_selected_p_idx_highest = not_selected_p_idxs[0]
        num_p = p_c_list[not_selected_p_idx_highest][0]
        addable_score = \
            100 * num_p * (not_selected_p_idx_highest + 1)
        if score_diff + addable_score > 0:
            score_per_p = 100 * (not_selected_p_idx_highest + 1)
            n_undersolved = math.ceil(abs(score_diff) / score_per_p)
            if n_undersolved < num_p:
                n_solved += n_undersolved
            # print('3:', n_solved)
    if n_solved > 0 and score_diff >= 0:
        min_n_solved = min(n_solved, min_n_solved)

print(min_n_solved)