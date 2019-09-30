using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Codeforces
{
	internal class Template
	{
		private void Solve()
		{
			var n = cin.NextInt();
			var towns = new Town[n];
			var adj = new List<Tuple<int, int>>[n];
			for (var i = 0; i < n; i++)
			{
				towns[i] = new Town(cin.NextInt(), cin.NextInt(), i);
				adj[i] = new List<Tuple<int, int>>();
			}
			var xx = towns.OrderBy(x => x.X).ToList();
			for (var i = 0; i < xx.Count; i++)
			{
				if (i - 1 >= 0)
				{
					adj[xx[i].Idx].Add(Tuple.Create(xx[i - 1].Idx, xx[i].X - xx[i - 1].X));
				}
				if (i + 1 < xx.Count)
				{
					adj[xx[i].Idx].Add(Tuple.Create(xx[i + 1].Idx, xx[i + 1].X - xx[i].X));
				}
			}
			var yy = towns.OrderBy(x => x.Y).ToList();
			for (var i = 0; i < yy.Count; i++)
			{
				if (i - 1 >= 0)
				{
					adj[yy[i].Idx].Add(Tuple.Create(yy[i - 1].Idx, yy[i].Y - yy[i - 1].Y));
				}
				if (i + 1 < yy.Count)
				{
					adj[yy[i].Idx].Add(Tuple.Create(yy[i + 1].Idx, yy[i + 1].Y - yy[i].Y));
				}
			}

			var dsu = DisjointSetSimple.createSets(n);
			var queue = new PriorityQueue<int, Tuple<int, int>>();
			for (var i = 0; i < adj.Length; i++)
			{
				foreach (var item in adj[i])
				{
					queue.Enqueue(item.Item2, Tuple.Create(i, item.Item1));
				}
			}
			var cost = 0L;
			while (queue.Any())
			{
				var front = queue.Dequeue();
				var value = front.Value;
				var key = front.Key;
				if (DisjointSetSimple.root(dsu, value.Item1) != DisjointSetSimple.root(dsu, value.Item2))
				{
					DisjointSetSimple.unite(dsu, value.Item1, value.Item2);
					cost += key;
				}
			}
			Console.WriteLine(cost);
		}

		public class Town
		{
			public int X, Y, Idx;

			public Town(int x, int y, int idx)
			{
				X = x;
				Y = y;
				Idx = idx;
			}
		}

		public class DisjointSetSimple
		{
			public static int[] createSets(int size)
			{
				int[] p = new int[size];
				for (int i = 0; i < size; i++)
					p[i] = i;
				return p;
			}

			public static int root(int[] p, int x)
			{
				return x == p[x] ? x : (p[x] = root(p, p[x]));
			}

			public static void unite(int[] p, int a, int b)
			{
				a = root(p, a);
				b = root(p, b);
				if (a != b)
					p[a] = b;
			}
		}

		public class PriorityQueue<TPriority, TValue> : ICollection<KeyValuePair<TPriority, TValue>>
		{
			private readonly List<KeyValuePair<TPriority, TValue>> baseHeap;
			private readonly IComparer<TPriority> comparer;

			public PriorityQueue()
				: this(Comparer<TPriority>.Default)
			{
			}

			public PriorityQueue(int capacity)
				: this(capacity, Comparer<TPriority>.Default)
			{
			}

			public PriorityQueue(int capacity, IComparer<TPriority> comparer)
			{
				if (comparer == null)
					throw new ArgumentNullException();

				baseHeap = new List<KeyValuePair<TPriority, TValue>>(capacity);
				this.comparer = comparer;
			}

			public PriorityQueue(IComparer<TPriority> comparer)
			{
				if (comparer == null)
					throw new ArgumentNullException();

				baseHeap = new List<KeyValuePair<TPriority, TValue>>();
				this.comparer = comparer;
			}

			public PriorityQueue(IEnumerable<KeyValuePair<TPriority, TValue>> data)
				: this(data, Comparer<TPriority>.Default)
			{
			}

			public PriorityQueue(IEnumerable<KeyValuePair<TPriority, TValue>> data, IComparer<TPriority> comparer)
			{
				if (data == null || comparer == null)
					throw new ArgumentNullException();

				this.comparer = comparer;
				baseHeap = new List<KeyValuePair<TPriority, TValue>>(data);
				// heapify data
				for (int pos = baseHeap.Count / 2 - 1; pos >= 0; pos--)
					HeapifyFromBeginningToEnd(pos);
			}

			public static PriorityQueue<TPriority, TValue> MergeQueues(PriorityQueue<TPriority, TValue> pq1, PriorityQueue<TPriority, TValue> pq2)
			{
				if (pq1 == null || pq2 == null)
					throw new ArgumentNullException();
				// ReSharper disable once PossibleUnintendedReferenceComparison
				if (pq1.comparer != pq2.comparer)
					throw new InvalidOperationException("Priority queues to be merged must have equal comparers");
				return MergeQueues(pq1, pq2, pq1.comparer);
			}

			public static PriorityQueue<TPriority, TValue> MergeQueues(PriorityQueue<TPriority, TValue> pq1, PriorityQueue<TPriority, TValue> pq2, IComparer<TPriority> comparer)
			{
				if (pq1 == null || pq2 == null || comparer == null)
					throw new ArgumentNullException();
				// merge data
				PriorityQueue<TPriority, TValue> result = new PriorityQueue<TPriority, TValue>(pq1.Count + pq2.Count, pq1.comparer);
				result.baseHeap.AddRange(pq1.baseHeap);
				result.baseHeap.AddRange(pq2.baseHeap);
				// heapify data
				for (int pos = result.baseHeap.Count / 2 - 1; pos >= 0; pos--)
					result.HeapifyFromBeginningToEnd(pos);

				return result;
			}

			public void Enqueue(TPriority priority, TValue value)
			{
				Insert(priority, value);
			}

			public KeyValuePair<TPriority, TValue> Dequeue()
			{
				if (!IsEmpty)
				{
					KeyValuePair<TPriority, TValue> result = baseHeap[0];
					DeleteRoot();
					return result;
				}
				else
					throw new InvalidOperationException("Priority queue is empty");
			}

			public TValue DequeueValue()
			{
				return Dequeue().Value;
			}

			public KeyValuePair<TPriority, TValue> Peek()
			{
				if (!IsEmpty)
					return baseHeap[0];
				else
					throw new InvalidOperationException("Priority queue is empty");
			}

			public TValue PeekValue()
			{
				return Peek().Value;
			}

			public bool IsEmpty
			{
				get { return baseHeap.Count == 0; }
			}

			private void ExchangeElements(int pos1, int pos2)
			{
				KeyValuePair<TPriority, TValue> val = baseHeap[pos1];
				baseHeap[pos1] = baseHeap[pos2];
				baseHeap[pos2] = val;
			}

			private void Insert(TPriority priority, TValue value)
			{
				KeyValuePair<TPriority, TValue> val = new KeyValuePair<TPriority, TValue>(priority, value);
				baseHeap.Add(val);

				// heap[i] have children heap[2*i + 1] and heap[2*i + 2] and parent heap[(i-1)/ 2];

				// heapify after insert, from end to beginning
				HeapifyFromEndToBeginning(baseHeap.Count - 1);
			}


			private int HeapifyFromEndToBeginning(int pos)
			{
				if (pos >= baseHeap.Count) return -1;

				while (pos > 0)
				{
					int parentPos = (pos - 1) / 2;
					if (comparer.Compare(baseHeap[parentPos].Key, baseHeap[pos].Key) > 0)
					{
						ExchangeElements(parentPos, pos);
						pos = parentPos;
					}
					else break;
				}
				return pos;
			}


			private void DeleteRoot()
			{
				if (baseHeap.Count <= 1)
				{
					baseHeap.Clear();
					return;
				}

				baseHeap[0] = baseHeap[baseHeap.Count - 1];
				baseHeap.RemoveAt(baseHeap.Count - 1);

				// heapify
				HeapifyFromBeginningToEnd(0);
			}

			private void HeapifyFromBeginningToEnd(int pos)
			{
				if (pos >= baseHeap.Count) return;

				// heap[i] have children heap[2*i + 1] and heap[2*i + 2] and parent heap[(i-1)/ 2];

				while (true)
				{
					// on each iteration exchange element with its smallest child
					int smallest = pos;
					int left = 2 * pos + 1;
					int right = 2 * pos + 2;
					if (left < baseHeap.Count && comparer.Compare(baseHeap[smallest].Key, baseHeap[left].Key) > 0)
						smallest = left;
					if (right < baseHeap.Count && comparer.Compare(baseHeap[smallest].Key, baseHeap[right].Key) > 0)
						smallest = right;

					if (smallest != pos)
					{
						ExchangeElements(smallest, pos);
						pos = smallest;
					}
					else break;
				}
			}

			public void Add(KeyValuePair<TPriority, TValue> item)
			{
				Enqueue(item.Key, item.Value);
			}

			public void Clear()
			{
				baseHeap.Clear();
			}

			public bool Contains(KeyValuePair<TPriority, TValue> item)
			{
				return baseHeap.Contains(item);
			}

			public int Count
			{
				get { return baseHeap.Count; }
			}

			public void CopyTo(KeyValuePair<TPriority, TValue>[] array, int arrayIndex)
			{
				baseHeap.CopyTo(array, arrayIndex);
			}

			public bool IsReadOnly
			{
				get { return false; }
			}

			public bool Remove(KeyValuePair<TPriority, TValue> item)
			{
				// find element in the collection and remove it
				int elementIdx = baseHeap.IndexOf(item);
				if (elementIdx < 0) return false;

				//remove element
				baseHeap[elementIdx] = baseHeap[baseHeap.Count - 1];
				baseHeap.RemoveAt(baseHeap.Count - 1);

				// heapify
				int newPos = HeapifyFromEndToBeginning(elementIdx);
				if (newPos == elementIdx)
					HeapifyFromBeginningToEnd(elementIdx);

				return true;
			}

			public IEnumerator<KeyValuePair<TPriority, TValue>> GetEnumerator()
			{
				return baseHeap.GetEnumerator();
			}

			IEnumerator IEnumerable.GetEnumerator()
			{
				return GetEnumerator();
			}
		}

		private static readonly Scanner cin = new Scanner();

		private static void Main()
		{
			new Template().Solve();
			Console.ReadLine();
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}