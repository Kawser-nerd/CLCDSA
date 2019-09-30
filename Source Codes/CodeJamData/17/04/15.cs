using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace code_jam_2k17_q
{
    class soln
    {
        public int points, num_added;
        public List<string> added;
        public char[,] grid;

        public soln(int N)
        {
            points = num_added = 0;
            added = new List<string>();
            grid = new char[N, N];
        }
    }
    public class D
    {
        static int num_calls = 0;

        static void copy_2d(char[,] dest, char[,] src, int N)
        {
            int i, max;

            max = N * N;
            for (i = 0; i < max; ++i)
            {
                dest[i / N, i % N] = src[i / N, i % N];
            }
        }

        /* Checks if grid is valid after adding at (r, c) */
        // O(n)
        static bool is_valid (char[,] grid, int N, int r, int c)
        {
            int i, j;
            int num_other;

            /* check along row */
            num_other = 0;
            for (i = 0; i < N; ++i)
            {
                if (grid[r, i] == 'x' || grid[r, i] == 'o')
                    ++num_other;
            }
            if (num_other > 1)
                return false;

            /* check along col */
            num_other = 0;
            for (i = 0; i < N; ++i)
            {
                if (grid[i, c] == 'x' || grid[i, c] == 'o')
                    ++num_other;
            }
            if (num_other > 1)
                return false;

            /* check along upward diagonal */
            num_other = 0;
            for (i = 0; i < N; ++i)
            {
                j = r + c - i;
                if ((j >= 0) && (j < N))
                    if (grid[i, j] == '+' || grid[i, j] == 'o')
                        ++num_other;
            }
            if (num_other > 1)
                return false;

            /* check along downward diagonal */
            num_other = 0;
            for (i = 0; i < N; ++i)
            {
                j = c - r + i;
                if ((j >= 0) && (j < N))
                    if (grid[i, j] == '+' || grid[i, j] == 'o')
                        ++num_other;
            }
            if (num_other > 1)
                return false;

            return true;
        }

        static int calc_points(char[,] grid, int N)
        {
            int i, j;
            int sum = 0;

            for (i = 0; i < N; ++i)
            {
                for (j = 0; j < N; ++j)
                {
                    sum += pts(grid[i, j]);
                }
            }

            return sum;
        }

        static void print_grid(char[,] grid, int N)
        {
            int i, j;

            for (i = 0; i < N; ++i)
            {
                for (j = 0; j < N; ++j)
                    Console.Write(grid[i, j] + " ");
                Console.WriteLine("");
            }
        }

        static bool try_add(char m, int r, int c, soln s, int N)
        {
            char existing;

            existing = s.grid[r, c];
            s.grid[r, c] = m;

            if (is_valid(s.grid, N, r, c))
            {
                ++s.num_added;
                s.added.Add(m + " " + (r + 1) + " " + (c + 1));
                return true;
            }

            s.grid[r, c] = existing;
            return false;
        }

        static bool try_add2(char m, int r, int c, soln s, int N, int[] rows, int[] cols, int[] ups, int[] downs)
        {
            char existing;
            bool valid, n_plus, n_times;

            existing = s.grid[r, c];
            s.grid[r, c] = m;

            n_plus = ((m == 'x') || (m == 'o')) && !((existing == 'x') || (existing == 'o'));
            n_times = ((m == '+') || (m == 'o')) && !((existing == '+') || (existing == 'o')); ;
            valid = !(n_plus && ((rows[r] > 0) || (cols[c] > 0)))
                && !(n_times && ((ups[r + c] > 0) || (downs[r - c + N - 1] > 0)));

            if (valid)
            {
                ++s.num_added;
                s.added.Add(m + " " + (r + 1) + " " + (c + 1));
                if (n_plus)
                {
                    ++rows[r];
                    ++cols[c];
                }
                if (n_times)
                {
                    ++ups[r + c];
                    ++downs[r - c + N - 1];
                }
                return true;
            }

            s.grid[r, c] = existing;
            return false;
        }

        static int pts(char model)
        {
            switch (model)
            {
                case '+':
                case 'x':
                    return 1;
                case 'o':
                    return 2;
                default:
                    return 0;
            }
        }

        static soln solve_smart_rec(char[,] grid, int N, int[] rows, int[] cols, int[] ups, int[] downs, int points, int r, int c)
        {
            int i, j;
            soln res, alt, best;
            string to_try;
            char current;
            bool not_plus, not_times;

            Console.WriteLine("Call number: " + (++num_calls));

            res = new soln(N);
            res.points = points;
            copy_2d(res.grid, grid, N);
            best = res;

            if (c >= N)
            {
                c = 0;
                r += 1;
            }
            if (r >= N)
                return res;

            switch(current = grid[r, c])
            {
                case 'o':
                    to_try = "o";
                    break;
                case '+':
                    to_try = "o+";
                    break;
                case 'x':
                    to_try = "ox";
                    break;
                case '.':
                    to_try = "o+x.";
                    break;
                default:
                    return null;
            }

            for (i = 1; i <= 3; ++i)
            {
                foreach (char m in to_try)
                {
                    not_plus = (m != current) && (m != '+');
                    not_times = (m != current) && (m != 'x');
                    if (not_plus && ((rows[r] > 0) || (cols[c] > 0)))
                        continue;
                    if (not_times && ((ups[r + c] > 0) || (downs[r - c + N - 1] > 0)))
                        continue;

                    if (not_plus)
                    {
                        ++rows[r];
                        ++cols[c];
                    }
                    if (not_times)
                    {
                        ++ups[r + c];
                        ++downs[r - c + N - 1];
                    }

                    res.grid[r, c] = m;
                    alt = solve_smart_rec(res.grid, N, rows, cols, ups, downs, points + pts(m) - pts(current), r + i % 2, c + i / 2);
                    if (alt.points > best.points)
                        best = alt;
                    res.grid[r, c] = current;

                    if (not_plus)
                    {
                        --rows[r];
                        --cols[c];
                    }
                    if (not_times)
                    {
                        --ups[r + c];
                        --downs[r - c + N - 1];
                    }
                }
            }

            return best;
        }

        static soln solve_greedy(char[,] grid, int N, string add_order)
        {
            soln result;
            int i, j, k, ell;

            result = new soln(N);
            copy_2d(result.grid, grid, N);

            for (i = 0; i < N; ++i)
            {
                for (j = 0; j < N; ++j)
                {
                    for (k = 0; k < add_order.Length; ++k)
                    {
                        if (result.grid[i,j] == add_order[k])
                        {
                            for (ell = 0; ell < k; ++ell)
                            {
                                if ((k == 2) && (ell == 1))
                                    continue;
                                if (try_add(add_order[ell], i, j, result, N))
                                    break;
                            }
                        }
                    }
                }
            }

            result.points = calc_points(result.grid, N);
            return result;
        }

        static soln solve_greedy2(char[,] grid, int N, int[] rows, int[] cols, int[] ups, int[] downs, string add_order, int r_off, int c_off)
        {
            soln result;
            int i, j, k, ell, r, c;

            result = new soln(N);
            copy_2d(result.grid, grid, N);
            result.points = calc_points(grid, N);

            for (i = 0; i < N; ++i)
            {
                r = (i + r_off) % N;
                for (j = 0; j < N; ++j)
                {
                    c = (j + c_off) % N;
                    for (k = 0; k < add_order.Length; ++k)
                    {
                        if (result.grid[r, c] == add_order[k])
                        {
                            for (ell = 0; ell < k; ++ell)
                            {
                                if ((k == 2) && (ell == 1))
                                    continue;
                                result.points -= pts(result.grid[r, c]);
                                if (try_add2(add_order[ell], r, c, result, N, rows, cols, ups, downs))
                                {
                                    result.points += pts(add_order[ell]); ;
                                    break;
                                }
                                else
                                {
                                    result.points += pts(result.grid[r, c]);
                                }
                            }
                        }
                    }
                }
            }
            
            return result;
        }

        // T(N) = N^2 + P * T(N)
        static soln solve(char[,] grid, int N, int points, int min_i, int min_j)
        {
            int i, j;
            soln best, current;

            best = new soln(N);
            best.points = points;
            copy_2d(best.grid, grid, N);

            for (i = min_i; i < N; ++i)
            {
                for (j = ((i == min_i) ? min_j: 0); j < N; ++j)
                {
                    /* Add model to blank */
                    if (grid[i, j] == '.')
                    {
                        grid[i, j] = '+';
                        if (is_valid(grid, N, i, j))
                        {
                            current = solve(grid, N, points + 1, i, j + 1);
                            if (current.points > best.points)
                            {
                                best = current;
                            }
                        }
                        grid[i, j] = 'x';
                        if (is_valid(grid, N, i, j))
                        {
                            current = solve(grid, N, points + 1, i, j + 1);
                            if (current.points > best.points)
                            {
                                best = current;
                            }
                        }
                        grid[i, j] = 'o';
                        if (is_valid(grid, N, i, j))
                        {
                            current = solve(grid, N, points + 2, i, j + 1);
                            if (current.points > best.points)
                            {
                                best = current;
                            }
                        }
                        grid[i, j] = '.';
                    }
                    /* Upgrade from '+' */
                    else if (grid[i, j] == '+')
                    {
                        grid[i, j] = 'o';
                        if (is_valid(grid, N, i, j))
                        {
                            current = solve(grid, N, points + 1, i , j + 1);
                            if (current.points > best.points)
                            {
                                best = current;
                            }
                        }
                        grid[i, j] = '+';
                    }
                    /* Upgrade from 'x' */
                    else if (grid[i, j] == 'x')
                    {
                        grid[i, j] = 'o';
                        if (is_valid(grid, N, i, j))
                        {
                            current = solve(grid, N, points + 1, i, j + 1);
                            if (current.points > best.points)
                            {
                                best = current;
                            }
                        }
                        grid[i, j] = 'x';
                    }
                }
            }

            return best;
        }

        static int[] read_ints(int num)
        {
            return Console.ReadLine()
                .Split(' ')
                .Take(num)
                .Select(s => Convert.ToInt32(s))
                .ToArray();
        }

        /* All row and column indices are 0-indexed except inside this function */
        public static void d()
        {
            int T, N, M;
            int i, j, t, m;
            int[] line;
            int[] rows, cols, ups, downs;
            int[] rows_o, cols_o, ups_o, downs_o;
            int r, c;
            string[] model;
            char[,] grid;
            soln result, best;
            
            T = read_ints(1)[0];
            for (t = 1; t <= T; ++t)
            {
                line = read_ints(2);
                N = line[0];
                M = line[1];
                grid = new char[N,N];
                /* Initialize Grid */
                for (i = 0; i < N; ++i)
                    for (j = 0; j < N; ++j)
                        grid[i, j] = '.';
                rows = new int[N];
                cols = new int[N];
                ups = new int[2 * N - 1];
                downs = new int[2 * N - 1];
                rows_o = new int[N];
                cols_o = new int[N];
                ups_o = new int[2 * N - 1];
                downs_o = new int[2 * N - 1];

                for (i = 0; i < N; ++i)
                    rows_o[i] = cols_o[i] = ups_o[i] = downs_o[i] = 0;
                for (i = N; i < 2*N - 1; ++i)
                    ups_o[i] = downs_o[i] = 0;

                /* Place models */
                for (m = 0; m < M; ++m)
                {
                    model = System.Console.ReadLine().Split(' ');
                    r = Convert.ToInt32(model[1]) - 1;
                    c = Convert.ToInt32(model[2]) - 1;
                    grid[r, c] = model[0][0];
                    if (grid[r,c] != '+')
                    {
                        ++rows_o[r];
                        ++cols_o[c];
                    }
                    if (grid[r,c] != 'x')
                    {
                        ++ups_o[r + c];
                        ++downs_o[r - c + N - 1];
                    }
                }

                /* Original Solution */
                //result = solve(grid, N, calc_points(grid, N), 0, 0);

                // Greedy solution
                /*
                result1 = solve_greedy(grid, N, "ox+.");
                result2 = solve_greedy(grid, N, "o+x.");
                result = result1.points > result2.points ? result1 : result2;
                Console.WriteLine("Result 1: " + result1.points + ", Result 2: " + result2.points);
                */
                // Try greedy2 from all row starts
                rows_o.CopyTo(rows, 0);
                cols_o.CopyTo(cols, 0);
                ups_o.CopyTo(ups, 0);
                downs_o.CopyTo(downs, 0);
                best = result = solve_greedy2(grid, N, rows, cols, ups, downs, "ox+.", N / 2, 0);
                for (i = 0; i < N; ++i)
                {
                    rows_o.CopyTo(rows, 0);
                    cols_o.CopyTo(cols, 0);
                    ups_o.CopyTo(ups, 0);
                    downs_o.CopyTo(downs, 0);
                    result = solve_greedy2(grid, N, rows, cols, ups, downs, "ox+.", i, 0);
                    if (result.points > best.points)
                        best = result;
                }

                result = best;
                

                // New recursive
                //result = solve_smart_rec(grid, N, rows, cols, ups, downs, calc_points(grid, N), 0, 0);

                /* Debug prints */
                /*
                Console.WriteLine("Original: ");
                print_grid(grid, N);
                Console.WriteLine("New: ");
                print_grid(result.grid, N);
                */
                /*
                for (i = 0; i < N; ++i)
                    for (j = 0; j < N; ++j)
                    {
                        if (grid[i,j] != result.grid[i, j])
                        {
                            ++result.num_added;
                            result.added.Add(result.grid[i, j] + " " + (i + 1) + " " + (j + 1));
                        }
                    }
                    */
                Console.WriteLine("Case #" + t + ": " + result.points + " " + result.num_added);
                result.added.ForEach(s => Console.WriteLine(s));
            }
        }
    }
}
