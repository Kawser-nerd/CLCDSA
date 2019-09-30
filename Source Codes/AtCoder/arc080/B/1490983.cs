using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;



namespace ConsoleApplication1.CodeForces
{
    public class LowerBoundSortedSet<T> : SortedSet<T>
    {

        private ComparerDecorator<T> _comparerDecorator;

        private class ComparerDecorator<T> : IComparer<T>
        {

            private IComparer<T> _comparer;

            public T LowerBound { get; private set; }
            public T UpperBound { get; private set; }

            private bool _reset = true;

            public void Reset()
            {
                _reset = true;
            }

            public ComparerDecorator(IComparer<T> comparer)
            {
                _comparer = comparer;
            }

            public int Compare(T x, T y)
            {
                int num = _comparer.Compare(x, y);
                if (_reset)
                {
                    LowerBound = y;
                    UpperBound = y;
                }
                if (num >= 0)
                {
                    LowerBound = y;
                    _reset = false;
                }
                if (num <= 0)
                {
                    UpperBound = y;
                    _reset = false;
                }
                return num;
            }
        }

        public LowerBoundSortedSet()
            : this(Comparer<T>.Default) { }

        public LowerBoundSortedSet(IComparer<T> comparer)
            : base(new ComparerDecorator<T>(comparer))
        {
            _comparerDecorator = (ComparerDecorator<T>)this.Comparer;
        }

        public T FindLowerBound(T key)
        {
            _comparerDecorator.Reset();
            this.Contains<T>(key);
            return _comparerDecorator.LowerBound;
        }

        public T FindUpperBound(T key)
        {
            _comparerDecorator.Reset();
            this.Contains<T>(key);
            return _comparerDecorator.UpperBound;
        }
    }
    public abstract class Heap<T> : IEnumerable<T>
    {
        private const int InitialCapacity = 0;
        private const int GrowFactor = 2;
        private const int MinGrow = 1;

        private int _capacity = InitialCapacity;
        private T[] _heap = new T[InitialCapacity];
        private int _tail = 0;

        public int Count { get { return _tail; } }
        public int Capacity { get { return _capacity; } }

        protected Comparer<T> Comparer { get; private set; }
        protected abstract bool Dominates(T x, T y);

        protected Heap() : this(Comparer<T>.Default)
        {
        }

        protected Heap(Comparer<T> comparer) : this(Enumerable.Empty<T>(), comparer)
        {
        }

        protected Heap(IEnumerable<T> collection)
            : this(collection, Comparer<T>.Default)
        {
        }

        protected Heap(IEnumerable<T> collection, Comparer<T> comparer)
        {
            if (collection == null) throw new ArgumentNullException("collection");
            if (comparer == null) throw new ArgumentNullException("comparer");

            Comparer = comparer;

            foreach (var item in collection)
            {
                if (Count == Capacity)
                    Grow();

                _heap[_tail++] = item;
            }

            for (int i = Parent(_tail - 1); i >= 0; i--)
                BubbleDown(i);
        }

        public void Add(T item)
        {
            if (Count == Capacity)
                Grow();

            _heap[_tail++] = item;
            BubbleUp(_tail - 1);
        }

        private void BubbleUp(int i)
        {
            if (i == 0 || Dominates(_heap[Parent(i)], _heap[i]))
                return; //correct domination (or root)

            Swap(i, Parent(i));
            BubbleUp(Parent(i));
        }

        public T GetMin()
        {
            if (Count == 0) throw new InvalidOperationException("Heap is empty");
            return _heap[0];
        }

        public T ExtractDominating()
        {
            if (Count == 0) throw new InvalidOperationException("Heap is empty");
            T ret = _heap[0];
            _tail--;
            Swap(_tail, 0);
            BubbleDown(0);
            return ret;
        }

        private void BubbleDown(int i)
        {
            int dominatingNode = Dominating(i);
            if (dominatingNode == i) return;
            Swap(i, dominatingNode);
            BubbleDown(dominatingNode);
        }

        private int Dominating(int i)
        {
            int dominatingNode = i;
            dominatingNode = GetDominating(YoungChild(i), dominatingNode);
            dominatingNode = GetDominating(OldChild(i), dominatingNode);

            return dominatingNode;
        }

        private int GetDominating(int newNode, int dominatingNode)
        {
            if (newNode < _tail && !Dominates(_heap[dominatingNode], _heap[newNode]))
                return newNode;
            else
                return dominatingNode;
        }

        private void Swap(int i, int j)
        {
            T tmp = _heap[i];
            _heap[i] = _heap[j];
            _heap[j] = tmp;
        }

        private static int Parent(int i)
        {
            return (i + 1) / 2 - 1;
        }

        private static int YoungChild(int i)
        {
            return (i + 1) * 2 - 1;
        }

        private static int OldChild(int i)
        {
            return YoungChild(i) + 1;
        }

        private void Grow()
        {
            int newCapacity = _capacity * GrowFactor + MinGrow;
            var newHeap = new T[newCapacity];
            Array.Copy(_heap, newHeap, _capacity);
            _heap = newHeap;
            _capacity = newCapacity;
        }

        public IEnumerator<T> GetEnumerator()
        {
            return _heap.Take(Count).GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }

    public class MaxHeap<T> : Heap<T>
    {
        public MaxHeap()
            : this(Comparer<T>.Default)
        {
        }

        public MaxHeap(Comparer<T> comparer)
            : base(comparer)
        {
        }

        public MaxHeap(IEnumerable<T> collection, Comparer<T> comparer)
            : base(collection, comparer)
        {
        }

        public MaxHeap(IEnumerable<T> collection) : base(collection)
        {
        }

        protected override bool Dominates(T x, T y)
        {
            return Comparer.Compare(x, y) >= 0;
        }
    }

    public class MinHeap<T> : Heap<T>
    {
        public MinHeap()
            : this(Comparer<T>.Default)
        {
        }

        public MinHeap(Comparer<T> comparer)
            : base(comparer)
        {
        }

        public MinHeap(IEnumerable<T> collection) : base(collection)
        {
        }

        public MinHeap(IEnumerable<T> collection, Comparer<T> comparer)
            : base(collection, comparer)
        {
        }

        protected override bool Dominates(T x, T y)
        {
            return Comparer.Compare(x, y) <= 0;
        }
    }
    static class _4032123
    {
        private static int Next()
        {
            int c;
            int res = 0;
            do
            {
                c = reader.Read();
                if (c == -1)
                    return res;
            } while (c < '0' || c > '9');
            res = c - '0';
            while (true)
            {
                c = reader.Read();
                if (c < '0' || c > '9')
                    return res;
                res *= 10;
                res += c - '0';
            }
        }
        private static readonly StreamReader reader = new StreamReader(Console.OpenStandardInput(1024 * 10), Encoding.ASCII, false, 1024 * 10);
        private static readonly StreamWriter writer = new StreamWriter(Console.OpenStandardOutput(1024 * 10), Encoding.ASCII, 1024 * 10);

        class Node
        {
            public int Number { get; set; }
            public char Letter { get; set; }

        }
        private static long Factorial(int i)
        {
            if (i <= 1)
                return 1;
            return i * Factorial(i - 1);
        }
        static void Main(String[] args)
        {
            var data = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();
            var H = data[0];
            var W = data[1];
            var N = int.Parse(Console.ReadLine().TrimEnd());
            data = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();

            var i = 1;
            var j = 1;
            var step = 0;
            var curH = H;
            var curW = W;
            var minH = 1;
            var minW = 1;
            var index = 0;
            var res = new long[H, W];
            while (true)
            {
                if(data[index] <= 0)
                {
                    index++;
                }
                if (index == N)
                {
                    break;
                }
                    res[i-1, j-1] = index+1;
                data[index]--;

                if (step == 0 && j == curW)
                {
                    step = 1;
                } else if(step == 1 && i == curH)
                {
                    step = 2;
                } else if(step==2 && j == minW)
                {
                    step = 3;
                    minW++;
                } else if(step == 3 && i == minH+1)
                {
                    step = 0;
                    minH++;
                    curW--;
                    curH--;
                }

                if(step == 0)
                {
                    j++;
                }
                if (step == 1)
                {
                    i++;
                }
                if(step == 2)
                {
                    j--;
                }
                if(step == 3)
                {
                    i--;
                }
            }

            var result = new List<string>();
            for(i = 0; i < H; i++)
            {
                var sb = new StringBuilder();
                for (j = 0; j < W; j++)
                {
                    sb.Append(res[i, j].ToString() + " ");
                }
                result.Add(sb.ToString());
            }
            writer.WriteLine(string.Join("\n", result));
            writer.Flush();


        }
    }
}