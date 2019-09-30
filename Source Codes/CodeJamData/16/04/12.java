import java.io.*;
import java.util.*;

public class D {
	static long walk(int[] aa, int k) {
		long n = 0;
		for (int i = 0; i < aa.length; i++)
			n = n * k + aa[i];
		return n + 1;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + t + ":");
			if (k > c * s)
				sb.append(" IMPOSSIBLE");
			else {
				int[] aa = new int[c];
				for (int i = 0, d = 0; i < s; i++) {
					if (d == k)
						break;
					for (int j = 0; j < c; j++)
						aa[j] = d < k ? d++ : 0;
					sb.append(" " + walk(aa, k));
				}
			}
			pw.println(sb);
		}
		pw.close();
	}
}
