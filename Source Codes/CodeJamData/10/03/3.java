import java.util.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int T = sc.nextInt();
		for (int t=0; t<T; t++) {
			System.out.println("case " + t);
			pw.print("Case #" + (t+1) + ": ");
			int R = sc.nextInt();
			long k = sc.nextLong();
			int N = sc.nextInt();
			long[] g = new long[N];
			for (int i=0; i<N; i++) g[i] = sc.nextLong();
			int[] next = new int[N];
			long[] add = new long[N];
			for (int i=0; i<N; i++) {
				int cur = i;
				long free = k;
				while (free >= g[cur]) {
					free -= g[cur];
					cur++;
					if (cur==N) cur = 0;
					if (cur == i) break;
				}
				next[i] = cur;
				add[i] = k - free;
			}
			long res = 0;
			int cur = 0;
			for (int i=0; i<R; i++) {
				res += add[cur];
				cur = next[cur];
			}
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
