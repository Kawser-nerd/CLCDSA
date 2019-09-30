using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.IO;

namespace ConsoleApplication4
{
    class Program
    {
        public class Attack
        {
            public long d;
            public long s;
            public long w;
            public long e;

            public Attack(long d, long s, long w, long e) {
                this.d = d;
                this.s = s;
                this.w = w;
                this.e = e;

            }
        }

        public class Def {
            public long w;
            public long e;
            public long h;

            public Def(long w, long e, long h) {
                this.w = w;
                this.e = e;
                this.h = h;
            }

        }

        static void Main(string[] args)
        {
            using(var prob = new CodeJamProblem('c', ProblemType.Small, 3))
            {
                int t = prob.ReadLineInt32();
                for(int c = 0; c < t; c++)
                {
                    LinkedList<Attack> sim = new LinkedList<Attack>();
                    
                    int n = prob.ReadLineInt32();
                    for(int i = 0; i < n; i++)
                    {
                        long[] b = prob.ReadInt64Array();
                        long w = b[2];
                        long d = b[0];
                        long e = b[3];
                        long s = b[4];
                        long dd = b[5];
                        long dp = b[6];
                        long ds = b[7];
                        LinkedListNode<Attack> nn = sim.First;
                        for(int j = 0; j < b[1]; j++)
                        {

                            while(nn != null && nn.Value.d < d)
                            {
                                nn = nn.Next;
                            }
                            if(nn == null)
                            {
                                sim.AddLast(new Attack(d, s, w, e));
                                nn = sim.Last;
                            }
                            else
                            {
                                sim.AddBefore(nn, new Attack(d, s, w, e));
                            }
                            
                            d += dd;
                            w += dp;
                            e += dp;
                            s += ds;
                        }


                    }
                    
                    LinkedList<Def> wall = new LinkedList<Def>();

                    int succ = 0;
                    long cd = 0;
                    List<Attack> day = new List<Attack>();
                    foreach(Attack a in sim) {
                        
                        if(a.d != cd) {
                            foreach(Attack aa  in day) {
                                wall.AddLast(new Def(aa.w, aa.e, aa.s));
                              }
                            day.Clear();
                        }
                        cd = a.d;
                        Attack ca = new Attack(a.d, a.s, a.w, a.e);
                        bool defd = false;
                        foreach(Def ddd in wall) {
                            if(ddd.h >= a.s) {
                                if(ddd.w <= a.w && ddd.e >= a.w) {
                                    if(ddd.e >= a.e) {
                                        defd = true;
                                        break;
                                    } else {
                                        a.w = ddd.e;
                                    }
                                }

                                if(ddd.e >= a.e && ddd.w <= a.e) {
                                    if(ddd.w <= a.w) {
                                        defd = true;
                                        break;
                                    } else {
                                        a.e = ddd.w;
                                    }
                                }
                            }
                            }
                           if(!defd)
                               succ++;
                            day.Add(ca);
                    
                        }
                    
                    prob.OutputCase(succ);                   



                   /* int[] xy = prob.ReadInt32Array();
                    int x = xy[0];
                    int y = xy[1];

                    string s = "";
                    for(int i = 0; i < Math.Abs(x); i++)
                    {
                        if(x < 0)
                        {
                            s += "EW";
                        }
                        else
                            s += "WE";
                    }

                    for(int i = 0; i < Math.Abs(y); i++)
                    {
                        if(y < 0)
                        {
                            s += "NS";
                        }
                        else
                            s += "SN";
                    }
                    prob.OutputCase(s);
                    */
                
                   /* Node cur = new Node(0, 0, 1, null);

                    List<Node> open = new List<Node>();
                    List<Node> closed = new List<Node>();

                    open.Add(cur);

                    while(open.Count > 0)
                    {
                        cur = open[0];
                        open.RemoveAt(0);

                        if(cur.x == x && cur.y == y)
                        {
                            //found
                            break;
                        }

                        Node n = new Node(cur.x + cur.d, cur.y, cur.d + 1, cur);
                        if(!open.Contains(n) && !closed.Contains(n))
                            open.Add(n);
                        n = new Node(cur.x - cur.d, cur.y, cur.d + 1, cur);
                        if(!open.Contains(n) && !closed.Contains(n))
                            open.Add(n);
                        n = new Node(cur.x, cur.y + cur.d, cur.d + 1, cur);
                        if(!open.Contains(n) && !closed.Contains(n))
                            open.Add(n);
                        n = new Node(cur.x, cur.y - cur.d, cur.d + 1, cur);
                        if(!open.Contains(n) && !closed.Contains(n))
                            open.Add(n);

                        closed.Add(cur);

                        Console.WriteLine(cur.d);
                    }

                    prob.OutputCase(cur.result());
                    */
                }
            }
        }
    }

    public class Node
    {
        public int x;
        public int y;
        public int d;
        public Node p;

        public Node(int x, int y, int d, Node p)
        {
            this.x = x;
            this.y = y;
            this.d = d;
            this.p = p;
        }

        public string result()
        {
            string s = "";
            Node n = this;
            while(n.p != null) {
                if(n.p.x < n.x)
                {
                    s  = "E" + s;
                }
                else if(n.p.x > n.x)
                {
                    s = "W" + s;
                }
                else if(n.p.y > n.y)
                {
                    s = "S" + s;
                }
                else
                {
                    s = "N" + s;
                }
                n = n.p;
            }
      
            return s;
        }
    }






    public class CodeJamProblem : IDisposable
    {
        private static readonly string filesDirectory = Path.Combine(Directory.GetParent(Environment.GetFolderPath(
            Environment.SpecialFolder.Personal)).FullName, "gcj\\");

        private static string GetProblemTypeName(ProblemType problemType)
        {
            switch(problemType)
            {
                case ProblemType.Sample:
                    return "sample";
                case ProblemType.Small:
                    return "small";
                case ProblemType.Large:
                    return "large";
            }
            throw new ArgumentException("Invalid problem type.", "problemType");
        }

        private int caseNumber;

        private StreamReader textReader;
        private StreamWriter textWriter;

        private bool disposed = false;

        public CodeJamProblem(char problem, ProblemType problemType, int attempt = 0)
            : this(
                Path.Combine(filesDirectory, char.ToUpper(problem).ToString() + "-" + GetProblemTypeName(problemType) +
                (problemType == ProblemType.Small ? "-attempt" + attempt.ToString() : string.Empty) + ".in")
            )
        {
        }

        public CodeJamProblem(string inputFileName)
        {
            this.InputFileName = inputFileName;
            this.OutputFileName = Path.ChangeExtension(this.InputFileName, ".out");

            this.textReader = new StreamReader(this.InputFileName);
            this.textWriter = new StreamWriter(this.OutputFileName);

            this.caseNumber = 1;
            this.StartTime = Environment.TickCount;
        }

        public int StartTime
        {
            get;
            private set;
        }

        public int ElapsedTime
        {
            get;
            private set;
        }

        public int CurrentCaseNumber
        {
            get { return this.caseNumber; }
        }

        public bool InputAvailable
        {
            get { return this.textReader.Peek() != -1; }
        }

        public string InputFileName
        {
            get;
            private set;
        }

        public string OutputFileName
        {
            get;
            private set;
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if(!disposed)
            {
                if(disposing)
                {
                    this.ElapsedTime = Environment.TickCount - this.StartTime;

                    textReader.Dispose();
                    textWriter.Dispose();

                    Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
                    Console.Beep();
                    Console.ReadKey(true);
                }
            }

            disposed = true;
        }

        public void OutputCase(params object[] values)
        {
            var parts = new string[values.Length];
            for(int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            OutputCase(string.Join(" ", parts));
        }

        public void OutputCase()
        {
            OutputCase((string)null);
        }

        public void OutputCase(string value)
        {
            WriteLine("Case #{0:#0}: {1}", this.caseNumber, value);
            this.caseNumber++;
        }

        public void WriteArrays<T>(T[][] entries)
        {
            for(int i = 0; i < entries.Length; i++)
                WriteArray(entries[i]);
        }

        public void WriteArray<T>(T[] values)
        {
            var parts = new string[values.Length];
            for(int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            WriteLine(string.Join(" ", parts));
        }

        public void WriteLines(string[] lines)
        {
            for(int i = 0; i < lines.Length; i++)
                WriteLine(lines[i]);
        }

        public void WriteLine(string format, params object[] arg)
        {
            Console.WriteLine(format, arg);
            this.textWriter.WriteLine(format, arg);
        }

        public void WriteLine(string line)
        {
            Console.WriteLine(line);
            this.textWriter.WriteLine(line);
        }

        public T[][] ReadArrays<T>(int count, Func<string, T> converter)
        {
            var entries = new T[count][];
            for(int i = 0; i < entries.Length; i++)
                entries[i] = ReadArray(converter);
            return entries;
        }

        public T[] ReadArray<T>(Func<string, T> converter)
        {
            var parts = ReadParts();
            var values = new T[parts.Length];
            for(int i = 0; i < values.Length; i++)
                values[i] = converter(parts[i]);
            return values;
        }

        public short[][] ReadInt16Arrays(int count)
        {
            var entries = new short[count][];
            for(int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt16Array();
            return entries;
        }

        public short[] ReadInt16Array()
        {
            var parts = ReadParts();
            var values = new short[parts.Length];
            for(int i = 0; i < values.Length; i++)
                values[i] = short.Parse(parts[i]);
            return values;
        }

        public int[][] ReadInt32Arrays(int count)
        {
            var entries = new int[count][];
            for(int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt32Array();
            return entries;
        }

        public int[] ReadInt32Array()
        {
            var parts = ReadParts();
            var values = new int[parts.Length];
            for(int i = 0; i < values.Length; i++)
                values[i] = int.Parse(parts[i]);
            return values;
        }

        public long[][] ReadInt64Arrays(int count)
        {
            var entries = new long[count][];
            for(int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt64Array();
            return entries;
        }

        public long[] ReadInt64Array()
        {
            var parts = ReadParts();
            var values = new long[parts.Length];
            for(int i = 0; i < values.Length; i++)
                values[i] = long.Parse(parts[i]);
            return values;
        }

        public double[][] ReadDoubleArrays(int count)
        {
            var entries = new double[count][];
            for(int i = 0; i < entries.Length; i++)
                entries[i] = ReadDoubleArray();
            return entries;
        }

        public double[] ReadDoubleArray()
        {
            var parts = ReadParts();
            var values = new double[parts.Length];
            for(int i = 0; i < values.Length; i++)
                values[i] = double.Parse(parts[i]);
            return values;
        }

        public string[] ReadParts()
        {
            return ReadLine().Split(' ');
        }

        public string[] ReadLines(int count)
        {
            var lines = new string[count];
            for(int i = 0; i < lines.Length; i++)
                lines[i] = ReadLine();
            return lines;
        }

        public short ReadLineInt16()
        {
            return short.Parse(ReadLine());
        }

        public int ReadLineInt32()
        {
            return int.Parse(ReadLine());
        }

        public long ReadLineInt64()
        {
            return long.Parse(ReadLine());
        }

        public double ReadLineDouble()
        {
            return double.Parse(ReadLine());
        }

        public string ReadLine()
        {
            return this.textReader.ReadLine();
        }
    }

    public enum ProblemType
    {
        Sample,
        Small,
        Large,
    }
}











