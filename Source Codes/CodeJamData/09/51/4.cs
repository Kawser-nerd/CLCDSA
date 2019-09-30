using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

class ProblemA
{
    private const bool parallel = false;

    class Case
    {
        private int caseNum;
        private int R, C;
        private string[] board;
        private HashSet<string> seen = new HashSet<string>();
        private string goal;

        private void readInput()
        {
            int[] tmp = readInts();
            R = tmp[0];
            C = tmp[1];
            board = new string[R];
            for (int i = 0; i < R; i++)
            {
                board[i] = readLine();
                goal += board[i].Replace('o', '.').Replace('x', 'o').Replace('w', 'o') + "|";
                board[i] = board[i].Replace('x', '.').Replace('w', 'o');
            }
        }

        public string DoCase()
        {
            string s = "";
            foreach (string b in board) s += b + "|";
            var q = new Queue<dynamic>();
            q.Enqueue(new { Moves = 0, Dangerous = false, State = s });
            while (q.Count > 0)
            {
                var d = q.Dequeue();
                s = d.State;
                if (seen.Contains(s))
                    continue;
                seen.Add(s);
                if (s == goal)
                    return string.Format("Case #{0}: {1}", caseNum, d.Moves);
                foreach (var v in generate(d))
                    if (!d.Dangerous || !v.Dangerous)
                        q.Enqueue(v);
            }
            return string.Format("Case #{0}: -1", caseNum);
        }

        IEnumerable<dynamic> generate(dynamic state)
        {
            int moves = state.Moves + 1;
            string st = state.State;
            char[][] board = Array.ConvertAll<string,char[]>(st.Trim('|').Split('|'), s => s.ToCharArray());
            for (int i = 0; i < board.Length; i++)
            {
                int j = board[i].IndexOf('o');
                while (j >= 0)
                {
                    if (j > 0 && j < C - 1 && board[i][j - 1] == '.' && board[i][j + 1] == '.')
                    {
                        board[i][j - 1] = 'o';
                        board[i][j] = '.';
                        bool danger = check(board);
                        yield return new { Moves = moves, Dangerous = danger, State = make(board) };
                        board[i][j - 1] = '.';
                        board[i][j + 1] = 'o';
                        danger = check(board);
                        yield return new { Moves = moves, Dangerous = danger, State = make(board) };
                        board[i][j + 1] = '.';
                        board[i][j] = 'o';
                    }
                    if (i > 0 && i < R - 1 && board[i - 1][j] == '.' && board[i + 1][j] == '.')
                    {
                        board[i - 1][j] = 'o';
                        board[i][j] = '.';
                        bool danger = check(board);
                        yield return new { Moves = moves, Dangerous = danger, State = make(board) };
                        board[i - 1][j] = '.';
                        board[i + 1][j] = 'o';
                        danger = check(board);
                        yield return new { Moves = moves, Dangerous = danger, State = make(board) };
                        board[i + 1][j] = '.';
                        board[i][j] = 'o';
                    }
                    j = (j == C - 1) ? -1 : board[i].IndexOf('o', j + 1);
                }
            }
        }

        bool check(char[][] board)
        {
            Dictionary<int, int> roots = new Dictionary<int, int>();
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (i >= R) break;
                    if (board[i][j] != 'o')
                        continue;
                    int v = i*C+j;
                    if (j > 0 && board[i][j - 1] == 'o')
                        roots[v] = roots[v - 1];
                    else
                        roots[v] = v;
                    while (roots[roots[v]] != roots[v])
                        roots[v] = roots[roots[v]];
                    if (i > 0 && board[i - 1][j] == 'o')
                    {
                        roots[roots[v]] = roots[v - C];
                        while (roots[roots[v]] != roots[v])
                            roots[v] = roots[roots[v]];
                    }
                }
            }
            return roots.Values.Distinct().Count() > 1;
        }

        string make(char[][] board)
        {
            string[] tmp = Array.ConvertAll<char[], string>(board, cs => new string(cs));
            return string.Join("|", tmp) + "|";
        }

        //////////////////////////////////////
        // Mostly template stuff below here //
        //////////////////////////////////////

        private Task<string> task;

        public Case(int num)
        {
            caseNum = num;
            readInput();
        }

        public void Start()
        {
            task = Task.Factory.StartNew(new Func<string>(DoCase));
        }

        public string Finish()
        {
            task.Wait();
            return task.Result;
        }
    }

    private static StreamReader input;
    private static StreamWriter output;
    private static int? firstCase, lastCase;

    public static void Main(string[] args)
    {
        input = new StreamReader(args[0] + ".in");
        output = new StreamWriter(args[0] + ".out");
        if (args.Length > 1)
            firstCase = int.Parse(args[1]);
        if (args.Length > 2)
            lastCase = int.Parse(args[2]);
        solution();
        output.Close();
        input.Close();
    }

    static void solution()
    {
        int T = readInt();
        var tests = new Case[T];
        for (int i = 1; i <= T; i++)
        {
            tests[i - 1] = new Case(i);
            if (i >= (firstCase ?? 1) && i <= (lastCase ?? T))
            {
                if (parallel)
                    tests[i - 1].Start();
                else
                {
                    output.WriteLine(tests[i - 1].DoCase());
                    output.Flush();
                }
            }
        }
        if (parallel)
        {
            for (int i = (firstCase ?? 1) - 1; i < (lastCase ?? T); i++)
            {
                output.WriteLine(tests[i].Finish());
                output.Flush();
            }
        }
    }

    static string readLine()
    {
        return input.ReadLine();
    }

    static int readInt()
    {
        return int.Parse(readLine());
    }

    static string[] readWords()
    {
        return readLine().Split();
    }

    static int[] readInts()
    {
        return Array.ConvertAll(readWords(), int.Parse);
    }
}

static class Extensions
{
    public static int IndexOf<T>(this T[] arr, T elem)
    {
        return Array.IndexOf(arr, elem);
    }

    public static int IndexOf<T>(this T[] arr, T elem, int startIdx)
    {
        return Array.IndexOf(arr, elem, startIdx);
    }
}
