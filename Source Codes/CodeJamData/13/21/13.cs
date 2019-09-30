using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1B2013 {
	class TaskA {
		private static int SolveSmall(int size, int[] motes, int offset) {
			//Console.WriteLine("{0}, ({1}), {2}", size, string.Join(" ", motes), offset);
			if(offset >= motes.Length) {
				return 0;
			} else if(size <= 1) {
				return motes.Length-offset;
			} else if(motes[offset] < size) {
				return SolveSmall(size + motes[offset], motes, offset+1);
			} else if(motes[offset] < 2*size - 1) {
				return 1+SolveSmall((2*size - 1) + motes[offset], motes, offset+1);
			} else {
				int steps = 0;
				int newsize = size;
				while(newsize < motes[offset]) {
					newsize = newsize*2-1;
					steps++;
				}
				return Math.Min(
						steps+SolveSmall(newsize, motes, offset),
						1+SolveSmall(size, motes, offset+1));
				/*return 1+Math.Min(
					SolveSmall(2*size-1, motes, offset),
					SolveSmall(size, motes, offset+1));*/
			}
		}

		public static void RunSmall() {
			int T = int.Parse(Console.ReadLine());
			for(int i=1; i<=T; i++) {
				var parts = Console.ReadLine().Split(' ');
				int A = int.Parse(parts[0]);
				int N = int.Parse(parts[1]);
				var motes = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
				var result = SolveSmall(A, motes, 0);
				Console.WriteLine("Case #{0}: {1}", i, result);
			}
		}
	}
}
