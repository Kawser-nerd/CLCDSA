import java.util.*;

class Alpha {
	public static void main(String[] arg) {
		Scanner in = new Scanner(System.in);
		int tcc = Integer.parseInt(in.next());
		for(int tci = 1; tci <= tcc; ++tci) {
			System.out.print("Case #" + tci + ":"); System.err.println();
			String[] poly = in.next().split("\\+");
			int k = Integer.parseInt(in.next());
			int d = Integer.parseInt(in.next());
			String[] sdict = new String[d];
			for(int i = 0; i != d; ++i) sdict[i] = in.next();
			int[][] dict = new int[d][];
			for(int i = 0; i != d; ++i) dict[i] = wordToArr(sdict[i]);
			if(k >= 1) {
				int ans = 0;
				for(int i1 = 0; i1 != d; ++i1) {
					int[] comb = combine(dict[i1]);
					ans = (ans + score(poly, comb)) % 10009;
				}
				System.out.print(" " + ans);
			}
			if(k >= 2) {
				int ans = 0;
				for(int i1 = 0; i1 != d; ++i1) for(int i2 = 0; i2 != d; ++i2) {
					int[] comb = combine(dict[i1], dict[i2]);
					ans = (ans + score(poly, comb)) % 10009;
				}
				System.out.print(" " + ans);
			}
			if(k >= 3) {
				int ans = 0;
				for(int i1 = 0; i1 != d; ++i1) for(int i2 = 0; i2 != d; ++i2) for(int i3 = 0; i3 != d; ++i3) {
					int[] comb = combine(dict[i1], dict[i2], dict[i3]);
					ans = (ans + score(poly, comb)) % 10009;
				}
				System.out.print(" " + ans);
			}
			if(k >= 4) {
				int ans = 0;
				for(int i1 = 0; i1 != d; ++i1) for(int i2 = 0; i2 != d; ++i2) for(int i3 = 0; i3 != d; ++i3) for(int i4 = 0; i4 != d; ++i4) {
					int[] comb = combine(dict[i1], dict[i2], dict[i3], dict[i4]);
					ans = (ans + score(poly, comb)) % 10009;
				}
				System.out.print(" " + ans);
			}
			if(k >= 5) {
				int ans = 0;
				for(int i1 = 0; i1 != d; ++i1) for(int i2 = 0; i2 != d; ++i2) for(int i3 = 0; i3 != d; ++i3) for(int i4 = 0; i4 != d; ++i4) for(int i5 = 0; i5 != d; ++i5) {
					int[] comb = combine(dict[i1], dict[i2], dict[i3], dict[i4], dict[i5]);
					ans = (ans + score(poly, comb)) % 10009;
				}
				System.out.print(" " + ans);
			}
			System.out.println();
		}
	}
	
	static int score(String[] poly, int[] comb) {
		int ret = 0;
		for(String term: poly) {
			int val = 1;
			for(char c: term.toCharArray()) val = (val * comb[c - 'a']) % 10009;
			ret = (ret + val) % 10009;
		}
		return ret;
	}
	
	static int[] wordToArr(String s) {
		int[] ret = new int[26];
		for(char c: s.toCharArray()) ++ret[c - 'a'];
		return ret;
	}
	
	static int[] combine(int[]... arrs) {
		int[] ret = new int[26];
		for(int[] arr: arrs) for(int i = 0; i != 26; ++i) ret[i] += arr[i];
		return ret;
	}
}
