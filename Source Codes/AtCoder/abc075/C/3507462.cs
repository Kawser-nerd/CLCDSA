using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;


#if DEBUG
using Microsoft.VisualStudio.TestTools.UnitTesting;
#endif

namespace competitive_programming
{
    public class Program
    {
        static void Main(string[] args)
        {
#if DEBUG
            var scanner = new IO.StreamScanner(File.Open("input.txt", FileMode.Open));
#else
            var scanner = new IO.StreamScanner(Console.OpenStandardInput());
#endif

            var n = scanner.Integer();
            var m = scanner.Integer();
            var graph = new BICC(n);
            for (int i = 0; i < m; i++)
                graph.AddEdge(scanner.Integer() - 1, scanner.Integer() - 1);
            graph.GetBicc();

            IO.Printer.Out.WriteLine(graph._bridges.Count());
            IO.Printer.Out.Flush();
        }
        
    }

    // ?????????
    // http://pakapa104.hatenablog.com/entry/2016/07/24/154557
    public class BICC
    {
        int _n;

        /*** ???? ***/
        List<List<int>> _graph;
        List<int> _depth;
        List<int> _par;
        Dictionary<Tuple<int, int>, int> _imosEdge;
        enum STAT { UNUSED, USED_DFS, BRIDGE };
        Dictionary<Tuple<int, int>, STAT> _edgeType;
        public List<Tuple<int, int>> _bridges;

        /*** ??????? ***/
        public List<int> Cmp;               // cmp[i] = ?? i ???????????????
        public int Num_cc;                  // ??????????
        public List<int> Size_of_vertex;    // ??????????????????
        public List<List<int>> G_cc;        // ???????????????????

        public BICC(int n)
        {
            _n = n;
            _graph = Enumerable.Range(0, _n).Select(v => new List<int>()).ToList();
            _edgeType = new Dictionary<Tuple<int, int>, STAT>();
        }

        public void AddEdge(int a, int b)
        {
            _graph[a].Add(b);
            _graph[b].Add(a);
            UpdateEdgeType(a, b, STAT.UNUSED);
        }

        public void GetBicc()
        {
            _imosEdge = new Dictionary<Tuple<int, int>, int>();
            _depth = Enumerable.Range(0, _n).Select(v => -1).ToList();
            _par = Enumerable.Range(0, _n).Select(v => -1).ToList();
            Cmp = Enumerable.Range(0, _n).Select(v => -1).ToList();
            Num_cc = 0;
            _bridges = new List<Tuple<int, int>>();
            Size_of_vertex = new List<int>();
            G_cc = new List<List<int>>();

            /***	????	***/
            DfsTreeConstruct(0, -1);

            foreach (var p in _edgeType)
            {
                var e = p.Key;
                var type = p.Value;
                if (type == STAT.UNUSED)
                {
                    UpdateImos(e.Item1, e.Item2);
                }
            }

            ImosFinal(0, -1);
            foreach (var key in _edgeType.Keys.ToList())
            {
                var e = key;
                var type = _edgeType[key];
                if (type == STAT.USED_DFS)
                {
                    if (_imosEdge[e] == 0)
                    {
                        _edgeType[e] = STAT.BRIDGE;
                        _bridges.Add(e);
                    }
                }
            }

            /***	???????	***/
            for (int i = 0; i < _n; i++)
            {
                int size_cc = ExtractCC(i, Num_cc);
                if (size_cc > 0)
                {
                    Size_of_vertex.Add(size_cc);
                    Num_cc++;
                }
            }

            // ????????????set????
            var G_cc_st = Enumerable.Range(0, Num_cc).Select(v => new HashSet<int>()).ToList();

            foreach (var p in _edgeType)
            {
                var e = p.Key;
                var type = p.Value;
                if (type == STAT.BRIDGE)
                {
                    G_cc_st[Cmp[e.Item1]].Add(Cmp[e.Item2]);
                    G_cc_st[Cmp[e.Item2]].Add(Cmp[e.Item1]);
                }
            }

            for (int i = 0; i < Num_cc; i++)
            {
                G_cc.Add(G_cc_st[i].ToList());
            }
        }

        Tuple<int, int> GetEdge(int a, int b)
        {
            if (a > b)
            {
                var tmp = a;
                a = b;
                b = tmp;
            }
            return new Tuple<int, int>(a, b);
        }

        void UpdateEdgeType(int a, int b, STAT type)
        {
            if (a < 0 || b < 0) return;			// dfs?-1?????????
            _edgeType[GetEdge(a, b)] = type;
        }

        void DfsTreeConstruct(int v, int pre)
        {
            if (_depth[v] != -1) return;
            _depth[v] = (pre == -1 ? 0 : _depth[pre] + 1);
            _par[v] = pre;
            UpdateEdgeType(pre, v, STAT.USED_DFS);

            foreach (var nxt in _graph[v])
            {
                if (nxt == pre) continue;
                DfsTreeConstruct(nxt, v);
            }
        }

        void UpdateImos(int a, int b)
        {
            if (_depth[a] < _depth[b])
            {
                var tmp = a;
                a = b;
                b = tmp;
            }

            // depth[a] > depth[b]: DFS???????? a->b ??
            if (_par[a] != -1)
            {
                var edge = GetEdge(a, _par[a]);
                if (!_imosEdge.ContainsKey(edge)) _imosEdge.Add(edge, 0);
                _imosEdge[edge]++;
            }
            if (_par[b] != -1)
            {
                var edge = GetEdge(b, _par[b]);
                if (!_imosEdge.ContainsKey(edge)) _imosEdge.Add(edge, 0);
                _imosEdge[edge]--;
            }
        }

        int ImosFinal(int v, int pre)
        {
            int t = 0;
            foreach (var nxt in _graph[v])
            {
                if (nxt != pre && _edgeType[GetEdge(nxt, v)] == STAT.USED_DFS)
                {
                    t += ImosFinal(nxt, v);
                }
            }
            var edge = GetEdge(v, pre);

            if (pre != -1)
            {
                if (!_imosEdge.ContainsKey(edge)) _imosEdge.Add(edge, 0);
                _imosEdge[edge] += t;
            }
            return pre == -1 ? 0 : _imosEdge[edge];
        }

        // 1?????????????????????????
        int ExtractCC(int v, int color)
        {
            if (Cmp[v] != -1) return 0;
            Cmp[v] = color;
            int t = 1;
            foreach (var nxt in _graph[v])
            {
                if (_edgeType[GetEdge(v, nxt)] != STAT.BRIDGE)
                {
                    t += ExtractCC(nxt, color);
                }
            }
            return t;
        }
    }
}

#if DEBUG
#endif

#region INOUT

namespace IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer : StreamWriter
    {
        static Printer()
        {
            Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false };
        }

        public static Printer Out { get; set; }

        public override IFormatProvider FormatProvider
        {
            get { return CultureInfo.InvariantCulture; }
        }

        public Printer(Stream stream)
            : base(stream, new UTF8Encoding(false, true))
        {
        }

        public Printer(Stream stream, Encoding encoding)
            : base(stream, encoding)
        {
        }

        public void Write<T>(string format, T[] source)
        {
            base.Write(format, source.OfType<object>().ToArray());
        }

        public void WriteLine<T>(string format, T[] source)
        {
            base.WriteLine(format, source.OfType<object>().ToArray());
        }
    }

    public class StreamScanner
    {
        public StreamScanner(Stream stream)
        {
            str = stream;
        }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof;

        public bool IsEndOfStream
        {
            get { return isEof; }
        }

        private byte read()
        {
            if (isEof) return 0;
            if (ptr < len) return buf[ptr++];
            ptr = 0;
            if ((len = str.Read(buf, 0, 1024)) > 0) return buf[ptr++];
            isEof = true;
            return 0;
        }

        public char Char()
        {
            byte b;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }

        public string ScanLine()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n'; b = (char)read())
                if (b == 0) break;
                else if (b != '\r') sb.Append(b);
            return sb.ToString();
        }

        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0;
            byte b;
            var ng = false;
            do b = read(); while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-')
            {
                ng = true;
                b = read();
            }
            for (; ; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                ret = ret * 10 + b - '0';
            }
        }

        public int Integer()
        {
            return (isEof) ? int.MinValue : (int)Long();
        }

        public double Double()
        {
            var s = Scan();
            return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN;
        }

        static T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n)
        {
            return enumerate(n, Char);
        }

        public string[] Scan(int n)
        {
            return enumerate(n, Scan);
        }

        public double[] Double(int n)
        {
            return enumerate(n, Double);
        }

        public int[] Integer(int n)
        {
            return enumerate(n, Integer);
        }

        public long[] Long(int n)
        {
            return enumerate(n, Long);
        }
    }
}

#endregion