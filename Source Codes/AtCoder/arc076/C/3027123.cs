using System;
using System.Collections.Generic;
using System.Linq;

namespace arc076_c
{
	class Program
	{
		static int[] x;
		static bool onedge(int a, int b)
		{
			if (a == 0 || a == x[0]) return true;
			if (b == 0 || b == x[1]) return true;
			return false;
		}
		static int howlong(int a, int b)
		{
			if (a == 0) return b;//up
			if (b == x[1]) return x[1] + a;//right
			if (a == x[0]) return x[1] + x[0] + (x[1] - b);//down
			else return x[1] + x[0] + x[1] + (x[0] - a);//left
		}
		static void Main(string[] args)
		{
			x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			List<Tuple<int, int>> list = new List<Tuple<int, int>>();
			for (int i = 0; i < x[2]; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				if (onedge(a[0], a[1]) && onedge(a[2], a[3]))
				{
					int n1 = howlong(a[0], a[1]); list.Add(new Tuple<int, int>(n1, i));
					int n2 = howlong(a[2], a[3]); list.Add(new Tuple<int, int>(n2, i));
				}
			}
			Tuple<int, int>[] arr = list.ToArray();
			Array.Sort(arr);
			Stack<int> stack = new Stack<int>();
			foreach (var tup in arr)
			{
				if (stack.Count == 0) stack.Push(tup.Item2);
				else if (stack.Peek() == tup.Item2) stack.Pop();
				else stack.Push(tup.Item2);
			}
			Console.WriteLine(stack.Count == 0 ? "YES" : "NO");
		}
	}
}