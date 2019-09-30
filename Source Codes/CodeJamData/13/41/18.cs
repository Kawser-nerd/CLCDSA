using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
	const long MOD = 1000002013;
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] ps = Console.ReadLine().Split();
			int N = int.Parse(ps[0]);
			int M = int.Parse(ps[1]);
			int[] o = new int[M];
			int[] e = new int[M];
			int[] p = new int[M];
			for (int i = 0; i < M; i++)
			{
				ps = Console.ReadLine().Split();
				o[i] = int.Parse(ps[0]);
				e[i] = int.Parse(ps[1]);
				p[i] = int.Parse(ps[2]);
			}
			
			// Calc base score
			long init = 0;
			for (int i = 0; i < M; i++)
				init += p[i] * Cost(N, e[i] - o[i]);
			
			// Calc best score
			long best = 0;
			int[] leave = new int[N];
			int[] enter = new int[N];
			for (int i = 0; i < M; i++)
			{
				leave[e[i] - 1] += p[i];
				enter[o[i] - 1] += p[i];
			}
			PriorityQueue<int> Q = new PriorityQueue<int>();
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < enter[i]; j++)
					Q.Push(-i);
				for (int j = 0; j < leave[i]; j++)
					best += Cost(N, i + Q.Pop());
			}

			Console.WriteLine("Case #" + CASE + ": " + ((init - best) % MOD));
		}
	}

	public static long Cost(int N, int stops)
	{
		long ret = 0;
		for (int i = 1; i <= stops; i++)
		{
			ret += N + 1 - i;
		}
		return ret;
	}

	public class PriorityQueue<T>
	{
		private T[] list;
		public int Count;
		public System.Collections.Generic.Comparer<T> Comparer;

		public PriorityQueue()
		{
			list = new T[1024];
			Count = 0;
			Comparer = System.Collections.Generic.Comparer<T>.Default;
		}

		public void Push(T value)
		{
			if (Count == list.Length)
			{
				T[] tmp = new T[list.Length * 2];
				System.Array.Copy(list, tmp, list.Length);
				list = tmp;
			}
			list[Count++] = value;
			int i = Count - 1;
			while (i > 0 && Comparer.Compare(list[i], list[parent(i)]) < 0)
			{
				T tmp = list[i];
				list[i] = list[parent(i)];
				list[parent(i)] = tmp;
				i = parent(i);
			}
		}

		public T Pop()
		{
			T ret = list[0];
			list[0] = list[--Count];
			int i = 0;
			while (true)
			{
				int left = (i * 2) + 1;
				if (left >= Count) break;
				int right = left + 1;
				int ind = left;
				if (right < Count && Comparer.Compare(list[left], list[right]) > 0)
					ind = right;
				if (Comparer.Compare(list[i], list[ind]) >= 0)
				{
					T tmp = list[i];
					list[i] = list[ind];
					list[ind] = tmp;
					i = ind;
				}
				else break;
			}
			return ret;
		}

		private int parent(int i)
		{
			return (i - 1) / 2;
		}
	}
}
