using System;

namespace AtCoder
{
    static class Solver
    {
        static IO io = new IO();

        public static void Solve()
        {
            io.ReadSplit();
            int N = io.Int();
            int M = io.Int();
            int Q = io.Int();

            bool[,] S = new bool[N + 1, M + 1];
            int[,] node = new int[N + 1, M + 1];
            int[,] v_edge = new int[N + 1, M + 1];
            int[,] h_edge = new int[N + 1, M + 1];
            for (int i = 1; i <= N; ++i)
            {
                io.Read();
                string str = io.String();
                for (int j = 1; j <= M; ++j)
                {
                    if (str[j - 1] == '1')
                    {
                        S[i, j] = true;
                        node[i, j] = node[i, j - 1] + node[i - 1, j] - node[i - 1, j - 1] + 1;
                        v_edge[i, j] = v_edge[i, j - 1] + v_edge[i - 1, j] - v_edge[i - 1, j - 1];
                        h_edge[i, j] = h_edge[i, j - 1] + h_edge[i - 1, j] - h_edge[i - 1, j - 1];
                        if (S[i, j - 1])
                        {
                            h_edge[i, j] += 1;
                        }
                        if (S[i - 1, j])
                        {
                            v_edge[i, j] += 1;
                        }
                    }
                    else
                    {
                        S[i, j] = false;
                        node[i, j] = node[i, j - 1] + node[i - 1, j] - node[i - 1, j - 1];
                        v_edge[i, j] = v_edge[i, j - 1] + v_edge[i - 1, j] - v_edge[i - 1, j - 1];
                        h_edge[i, j] = h_edge[i, j - 1] + h_edge[i - 1, j] - h_edge[i - 1, j - 1];
                    }
                }
            }

            for (int i = 0; i < Q; ++i)
            {
                io.ReadSplit();
                int x1 = io.Int();
                int y1 = io.Int();
                int x2 = io.Int();
                int y2 = io.Int();
                int node_sum = node[x2, y2] - node[x2, y1 - 1] - node[x1 - 1, y2] + node[x1 - 1, y1 - 1];
                int v_edge_sum = v_edge[x2, y2] - v_edge[x2, y1 - 1] - v_edge[x1, y2] + v_edge[x1, y1 - 1];
                int h_edge_sum = h_edge[x2, y2] - h_edge[x2, y1] - h_edge[x1 - 1, y2] + h_edge[x1 - 1, y1];
                io.WriteLine(node_sum - v_edge_sum - h_edge_sum);
            }
        }
    }
}
namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Solver.Solve();
        }
    }
    class IO
    {
        private string[] _Inputs;
        private int _Index;
        public void Read()
        {
            _Inputs = new string[1];
            _Inputs[0] = Console.ReadLine();
            _Index = 0;
        }
        public void ReadSplit()
        {
            _Inputs = Console.ReadLine().Split(' ');
            _Index = 0;
        }
        public string String()
        {
            return _Inputs[_Index++];
        }
        public string[] String(int xCount)
        {
            string[] rv = new string[xCount];
            Array.Copy(_Inputs, _Index, rv, 0, xCount);
            _Index += xCount;
            return rv;
        }
        public int Int()
        {
            return int.Parse(_Inputs[_Index++]);
        }
        public int[] Int(int xCount)
        {
            int[] rv = new int[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = int.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public long Long()
        {
            return long.Parse(_Inputs[_Index++]);
        }
        public long[] Long(int xCount)
        {
            long[] rv = new long[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = long.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public void Write(int xInt)
        {
            Console.Write(xInt.ToString());
        }
        public void Write(long xLong)
        {
            Console.Write(xLong.ToString());
        }
        public void Write(string xStr)
        {
            Console.Write(xStr);
        }
        public void WriteLine(int xInt)
        {
            Console.WriteLine(xInt.ToString());
        }
        public void WriteLine(long xLong)
        {
            Console.WriteLine(xLong.ToString());
        }
        public void WriteLine(string xStr)
        {
            Console.WriteLine(xStr);
        }
    }
}