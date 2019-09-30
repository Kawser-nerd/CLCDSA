using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split();
                int B = int.Parse(s[0]);
                int N = int.Parse(s[1]);
                string[] sM = Console.ReadLine().Split();
                List<int> M = sM.ToList().ConvertAll(_s => int.Parse(_s));
                long ret = whichBarber2(N, M);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int whichBarber2(int N, List<int> M)
        {
            long minTime = 0;
            long maxTime = 100000;
            maxTime *= N;

            while (true)
            {
                long midTime = (minTime + maxTime + 1) / 2;
                long started = 0;
                long starting = 0;
                for (int i = 0; i < M.Count; i++)
                {
                    started += (midTime+M[i]-1) / M[i];
                    if (midTime % M[i] == 0) starting++;
                }
                if (started >= N)
                {
                    maxTime = midTime - 1;
                }
                else if (started + starting < N)
                {
                    minTime = midTime + 1;
                }
                else
                {
                    int idx = (int)(N - started);
                    for (int i = 0; i < M.Count; i++)
                    {
                        if (midTime % M[i] == 0)
                        {
                            if (idx == 1) return i + 1;
                            idx--;
                        }
                    }
                }
            }
        }

        private class Barber : IComparable
        {
            public long readyTime;
            public int idx;

            public int CompareTo(object obj)
            {
                Barber bObj = (Barber)obj;
                if (bObj.readyTime != this.readyTime) return this.readyTime.CompareTo(bObj.readyTime);
                return this.idx.CompareTo(bObj.idx);
            }
        }

        private int whichBarber(int N, List<int> M)
        {
            MinHeap<Barber> mh = new MinHeap<Barber>();
            for (int i = 0; i < M.Count; i++)
            {
                Barber b = new Barber();
                b.idx = i;
                b.readyTime = 0;
                mh.Add(b);
            }

            for (int i = 0; i < N - 1; i++)
            {
                Barber b = mh.ExtractDominating();
                b.readyTime += M[b.idx];
                mh.Add(b);
            }
            Barber myBarber = mh.ExtractDominating();
            return myBarber.idx + 1;
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

            protected Heap()
                : this(Comparer<T>.Default)
            {
            }

            protected Heap(Comparer<T> comparer)
                : this(Enumerable.Empty<T>(), comparer)
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

            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
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

            public MaxHeap(IEnumerable<T> collection)
                : base(collection)
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

            public MinHeap(IEnumerable<T> collection)
                : base(collection)
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

    }
}
