using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProgrammingContest
{
    class MainClass
    {
        Scanner sc;
        static void Main(string[] args)
        {
            new MainClass().solve();
        }

        class Point
        {
            public double x, y;
            public double r;
            public Point() { }
            public Point(double x, double y, double r)
            {
                this.x = x;
                this.y = y;
                this.r = r;
            }
            public static double dist(Point a, Point b)
            {
                double xDist = a.x - b.x;
                double yDist = a.y - b.y;
                return Math.Sqrt(xDist * xDist + yDist * yDist);
            }
        }
        class State : IComparable<State>
        {
            public double dist;
            public int idx;
            public State(double dist, int idx)
            {
                this.dist = dist;
                this.idx = idx;
            }
            public int CompareTo(State other)
            {
                return Math.Sign(this.dist - other.dist);
            }
        }
        const double INF = 1e18;
        bool debugMode = false;
        void solve()
        {
            if (debugMode)
            {
                String backPath = "..";
                char dirSep = System.IO.Path.DirectorySeparatorChar;
                String inFilePath = backPath + dirSep + backPath + dirSep + "in.txt";
                sc = new Scanner(new System.IO.StreamReader(inFilePath));
            }
            else
            {
                sc = new Scanner();
            }

            Point start = new Point(sc.NextInt(), sc.NextInt(), 0);
            Point goal = new Point(sc.NextInt(), sc.NextInt(), 0);
            int n = sc.NextInt();
            Point[] barrier = new Point[n + 2];
            for (int i = 0; i < n; i++)
            {
                barrier[i + 1] = new Point(sc.NextInt(), sc.NextInt(), sc.NextInt());
            }
            barrier[0] = start;
            barrier[n + 1] = goal;
            SkewHeap<State> heap = new SkewHeap<State>();
            double[] minDist = new double[n + 2];
            double[,] pDist = new double[n + 2, n + 2];
            for (int i = 0; i < n + 2; i++)
            {
                pDist[i, i] = 0;
                for (int j = i + 1; j < n + 2; j++)
                {
                    pDist[i, j] = pDist[j, i] = Math.Max(0.0, Point.dist(barrier[i], barrier[j]) - barrier[i].r - barrier[j].r);
                }
            }
            for (int i = 0; i < n + 2; i++)
            {
                minDist[i] = INF;
            }
            heap.push(new State(0, 0));
            minDist[0] = 0;
            while (!heap.isEmpty())
            {
                State nowState = heap.poll();
                //Console.Error.WriteLine(heap.Count);
                if (minDist[nowState.idx] < nowState.dist)
                {
                    continue;
                }
                for (int i = 0; i < n + 2; i++)
                {
                    if (i != nowState.idx)
                    {
                        double nextDist = nowState.dist + pDist[i, nowState.idx];
                        if (nextDist < minDist[i])
                        {
                            minDist[i] = nextDist;
                            heap.push(new State(nextDist, i));
                        }
                    }
                }
            }
            Console.WriteLine(minDist[n + 1]);
        }
    }

    class SkewHeap<T> where T : IComparable<T>
    {
        private class HeapNode
        {
            public HeapNode l, r;
            public T val;

            public HeapNode(T val)
            {
                this.val = val;
                l = r = null;
            }
            public static HeapNode meld(HeapNode leftNode, HeapNode rightNode)
            {
                if (leftNode == null)
                {
                    return rightNode;
                }
                if (rightNode == null)
                {
                    return leftNode;
                }
                if (leftNode.val.CompareTo(rightNode.val) > 0)
                {
                    var t = rightNode;
                    rightNode = leftNode;
                    leftNode = t;
                }
                leftNode.r = meld(leftNode.r, rightNode);
                var t2 = leftNode.l;
                leftNode.l = leftNode.r;
                leftNode.r = t2;
                return leftNode;
            }
        }
        private HeapNode topNode;
        private int count_;

        public int Count { get { return this.count_; } }

        public SkewHeap()
        {
            this.topNode = null;
            this.count_ = 0;
        }
        public void pop()
        {
            this.topNode = HeapNode.meld(this.topNode.l, this.topNode.r);
            this.count_--;
        }
        public T top()
        {
            return this.topNode.val;
        }
        public void push(T val)
        {
            this.topNode = HeapNode.meld(this.topNode, new HeapNode(val));
            this.count_++;
        }
        public T poll()
        {
            T retVal = this.top();
            this.pop();
            return retVal;
        }
        public bool isEmpty()
        {
            return this.topNode == null;
        }
        public void merge(SkewHeap<T> otherHeap)
        {
            this.count_ += otherHeap.Count;
            this.topNode = HeapNode.meld(this.topNode, otherHeap.topNode);
        }
    }

    class Scanner
    {
        Queue<String> buffer;
        char[] sep;
        System.IO.TextReader reader;
        public Scanner()
        {
            this.buffer = new Queue<string>();
            this.sep = new char[] { ' ' };
            this.reader = Console.In;
        }
        public Scanner(System.IO.TextReader reader)
        {
            this.buffer = new Queue<string>();
            this.sep = new char[] { ' ' };
            this.reader = reader;
        }
        private void checkBuffer()
        {
            if (this.buffer.Count == 0)
            {
                String[] buf = this.reader.ReadLine().Split(this.sep);
                foreach (String str in buf)
                {
                    this.buffer.Enqueue(str);
                }
            }
        }

        public String Next()
        {
            this.checkBuffer();
            return this.buffer.Dequeue();
        }

        public int NextInt()
        {
            this.checkBuffer();
            return int.Parse(this.Next());
        }
        public double NextDouble()
        {
            return double.Parse(this.Next());
        }

        public long NextLong()
        {
            return long.Parse(this.Next());
        }
    }
}