package r1b2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
		
		Scanner inp = new Scanner(new File("garbled_email_dictionary.txt"));
		dict = new TreeSet<String>();
		while (inp.hasNext()) {
			dict.add(inp.next());
		}
		inp.close();

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			s = in.next();
			memo = new int[s.length()][s.length()+1];
			for (int[] mm : memo) Arrays.fill(mm, -1);
			out.println(solve(0, s.length()));
		}
		
		out.flush();
	}

	static int[][] memo;
	static SortedSet<String> dict;
	static String s;
	
	static int solve(int pos, int last) {
		if (pos >= s.length()) return 0;
		if (memo[pos][last] != -1) return memo[pos][last];
		
		int res = Integer.MAX_VALUE;
		for (String ss : dict) {
			if (ss.length() > s.length() - pos) continue;
			int ind[] = change(ss, pos);
			if (ind == null) continue;
			if (ind.length == 0) {
				int cur = solve(pos + ss.length(), last);
				if (cur < res) res = cur;
				continue;
			}
			if (last != s.length() && ind[0] - last < 5) continue;
			int cur = solve(pos + ss.length(), ind[1]);
			if (cur == Integer.MAX_VALUE) continue;
			cur += ind[2];
			if (cur < res) res = cur;
		}
		
		return memo[pos][last] = res;
	}
	
	static int[] change(String ss, int pos) {
		int res = -1, first = -1, cnt = 0;
		for (int i = 0; i < ss.length(); i++) {
			if (ss.charAt(i) != s.charAt(i+pos)) {
				if (res == -1 || i+pos - res >= 5) {
					res = i+pos;
					if (first == -1) first = res;
					cnt++;
				}
				else {
					return null;
				}
			}
		}
		return res == -1 ? new int[]{} : new int[]{first, res, cnt};
	}
}





