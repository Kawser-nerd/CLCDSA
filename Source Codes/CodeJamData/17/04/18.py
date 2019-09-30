
def add_more_rooks(N, existing_rooks):
    filled_rows = set([x[0] for x in existing_rooks])
    filled_columns = set([x[1] for x in existing_rooks])

    free_rows = [x for x in range(1, N + 1) if x not in filled_rows]
    free_columns = [x for x in range(1, N + 1) if x not in filled_columns]

    added_rooks = set(zip(free_rows, free_columns))
    return added_rooks

def bishop_hits(N, bishop):
    hit_positions = set([bishop])

    nw_moves = min(bishop[0], bishop[1])
    for i in range(1, nw_moves):
        hit_positions.add((bishop[0] - i, bishop[1] - i))
    sw_moves = min(N - bishop[0] + 1, bishop[1])
    for i in range(1, sw_moves):
        hit_positions.add((bishop[0] + i, bishop[1] - i))
    ne_moves = min(bishop[0], N - bishop[1] + 1)
    for i in range(1, ne_moves):
        hit_positions.add((bishop[0] - i, bishop[1] + i))
    se_moves = min(N - bishop[0] + 1, N - bishop[1] + 1)
    for i in range(1, se_moves):
        hit_positions.add((bishop[0] + i, bishop[1] + i))
    return hit_positions

def add_more_bishops(N, existing_bishops):
    filled_positions = set()
    for bishop in existing_bishops:
        filled_positions = filled_positions.union(bishop_hits(N, bishop))

    added_bishops = set()

    min_bound = 1
    max_bound = N
    while min_bound <= max_bound:

        for moving_pos in range(min_bound, max_bound + 1):
            candidate_bishop = (min_bound, moving_pos)
            if candidate_bishop not in filled_positions:
                added_bishops.add(candidate_bishop)
                filled_positions = filled_positions.union(bishop_hits(N, candidate_bishop))
            candidate_bishop = (max_bound, moving_pos)
            if candidate_bishop not in filled_positions:
                added_bishops.add(candidate_bishop)
                filled_positions = filled_positions.union(bishop_hits(N, candidate_bishop))                
            candidate_bishop = (moving_pos, min_bound)
            if candidate_bishop not in filled_positions:
                added_bishops.add(candidate_bishop)
                filled_positions = filled_positions.union(bishop_hits(N, candidate_bishop))
            candidate_bishop = (moving_pos, max_bound)
            if candidate_bishop not in filled_positions:
                added_bishops.add(candidate_bishop)
                filled_positions = filled_positions.union(bishop_hits(N, candidate_bishop))
                
        min_bound += 1
        max_bound -= 1
    return added_bishops

def fashion_show_solve(N, existing_rooks, existing_bishops):
    added_rooks = add_more_rooks(N, existing_rooks)
    added_bishops = add_more_bishops(N, existing_bishops)
    
    final_score = len(existing_rooks) + len(existing_bishops) + len(added_rooks) + len(added_bishops)

    added_figures = set()
    for rook in added_rooks:
        if (rook in existing_bishops) or (rook in added_bishops):
            added_figures.add("o" + " " + str(rook[0]) + " " + str(rook[1]))
        else:
            added_figures.add("x" + " " + str(rook[0]) + " " + str(rook[1]))
    for bishop in added_bishops:
        if (bishop in existing_rooks) or (bishop in added_rooks):
            added_figures.add("o" + " " + str(bishop[0]) + " " + str(bishop[1]))
        else:
            added_figures.add("+" + " " + str(bishop[0]) + " " + str(bishop[1]))
            
    return final_score, list(added_figures)

def fashion_show_main(input_filename, output_filename):
    f = open(input_filename, "rb")
    output_f = open(output_filename, "w")
    
    T = int(f.readline().split()[0])
    for i in range(1, T + 1):
        N, fig_count = [int(x) for x in f.readline().split()]
        existing_rooks = set()
        existing_bishops = set()
        for j in range(fig_count):
            existing_figure = f.readline().split()
            position = tuple([int(existing_figure[1]), int(existing_figure[2])])
            if existing_figure[0] == "o":
                existing_rooks.add(position)
                existing_bishops.add(position)
            if existing_figure[0] == "+":
                existing_bishops.add(position)
            if existing_figure[0] == "x":
                existing_rooks.add(position)                
        final_score, added_figures = fashion_show_solve(N, existing_rooks, existing_bishops)
        output_f.write("Case #" + str(i) + ": " + str(final_score) + " " + str(len(added_figures)) + "\n")
        for figure in added_figures:
            output_f.write(figure + "\n")
    return 1

fashion_show_main("D-large.in", "D-large.out")
