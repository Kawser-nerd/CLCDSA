using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program {
	static void Main(string[] args) {
		new Calc().Solve();
		return;
	}

	public class Calc {
		int N;
		public void Solve() {
			N = ReadLine<int>();
			var a = ReadLine<int>(' ');
			long sum = 1;
			long tmp = 1;
			for (int i = 1; i < N; i++) {
				tmp = a[i] > a[i - 1] ? tmp + 1 : 1;
				sum += tmp;
			}
			sum.WL();
			return;
		}
	}

	public static T[] ReadLine<T>(params char[] separators) {
		return Console.ReadLine()
			.Split(separators)
			.Where(_ => _.Length > 0)
			.Select(_ => (T)Convert.ChangeType(_, typeof(T)))
			.ToArray();
	}
	public static T ReadLine<T>() {
		return (T)Convert.ChangeType(Console.ReadLine(), typeof(T));
	}
	public static List<T> ReadLines<T>(int N) {
		List<T> rt = new List<T>();
		for (int i = 0; i < N; i++) {
			T item = (T)Convert.ChangeType(Console.ReadLine(), typeof(T));
			rt.Add(item);
		}
		return rt;
	}
}
public static class Utils {
	public static void WL(this object obj) {
		Console.WriteLine(obj);
	}
	public static string Docking<T>(this IEnumerable<T> collection, Func<T, string> filter = null) {
		StringBuilder sb = new StringBuilder();
		foreach (var item in collection) {
			string str = filter != null ? filter(item) : item.ToString();
			sb.Append(str);
		}
		return sb.ToString();
	}
	public static string RangeDocking<T>(this IEnumerable<T> collection,
		int start, int end, Func<T, string> filter = null) {
		if (start > collection.Count()) throw new IndexOutOfRangeException();
		if (end < 0) throw new IndexOutOfRangeException();
		StringBuilder sb = new StringBuilder();
		for (int i = start; i < end; i++) {
			string str = filter != null ? filter(collection.ElementAt(i)) : collection.ElementAt(i).ToString();
			sb.Append(str);
		}
		return sb.ToString();
	}
	public static void WriteLineAll<T>(this IEnumerable<T> collection) {
		foreach (var item in collection) {
			item.WL();
		}
	}
}