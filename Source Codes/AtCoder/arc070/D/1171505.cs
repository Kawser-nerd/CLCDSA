#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Text;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(Console.ReadLine());
	int[] G() => Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var I = G();
		int A = I[0], B = I[1], N = A + B;
		if (A <= B) Console.WriteLine("Impossible");
		else
		{
			var st = new Stack<int>();
			for (var i = 0; i < A + B; i++)
			{
				if (st.Count == 0 || Ask(st.Peek(), i)) st.Push(i);
				else st.Pop();
			}
			var h = st.Peek();
			var sb = new StringBuilder(N);
			for (var i = 0; i < N; i++) sb.Append(Ask(h, i) ? 1 : 0);
			Console.WriteLine("! " + sb.ToString());
		}
		Console.Out.Flush();
	}
	bool Ask(int a, int b)
	{
		Console.WriteLine("? {0} {1}", a, b);
		Console.Out.Flush();
		return Console.ReadLine() == "Y";
	}
}