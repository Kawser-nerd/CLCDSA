using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AIZU {
	class Program {
		#region Reserve
		static int cin() { return cin(-1); }
		static int cin(int D) {
			string s = Console.ReadLine();
			if (string.IsNullOrEmpty(s))
				return D;
			return int.Parse(s);
		}
		static int[] cins(char spliter) {
			string s = Console.ReadLine();
			if (string.IsNullOrEmpty(s))
				return new int[] { };
			string[] ss = s.Split(spliter);
			int[] Res = new int[ss.Length];
			for (int i = 0; i < ss.Length; i++)
				Res[i] = int.Parse(ss[i]);
			return Res;
		}
		static int[] cins() { return cins(' '); }
		static void print(object j) { Console.WriteLine(j.ToString()); }
		static void print(string j) { Console.WriteLine(j); }
		#endregion
		
		static void Main(string[] args) {
			Queue<string> Next = new Queue<string>();
			Stack<string> Prev= new Stack<string>();
			int n = cin();
			string[] A = Console.ReadLine().Split();
			for (int i = 0; i < n; i++) {
				if ((i&1)==0) Next.Enqueue(A[i]);
				else Prev.Push(A[i]);
			}
			string[] Res = new string[n];
			int pc = Prev.Count;
			for (int i = 0; i < pc; i++) {
				Res[i] = Prev.Pop();
			}
			for (int i = pc; i <n; i++) {
				Res[i] = Next.Dequeue();
			}
			if ((n & 1) == 1) Res = Res.Reverse().ToArray();
			print(string.Join(" ",Res));
		}
		
	}
}