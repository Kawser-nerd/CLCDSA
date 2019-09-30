using System;

namespace AtCoderPractice {
	public class Program {
		public static void Main() {
			string[] args = Console.ReadLine().Split(' ');
			int[] Lngs = new int[11];
			foreach (var str in args) {
				int Lng;
				if (Int32.TryParse(str,out Lng)) {
					Lngs[Lng]++;
				}
			}
			if ((Lngs[5] == 2) && (Lngs[7] == 1)) {
				Console.WriteLine("YES");
			} else {
				Console.WriteLine("NO");
			}
//			Console.ReadLine();
		}
	}
}