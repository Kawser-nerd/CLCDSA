import java.io.*;
import java.util.*;

public class C {
	static long value(int i, int m, int b) {
		long n = 1;
		for (int k = 0; k < m; k++) {
			n = n * b + i % 2;
			i /= 2;
		}
		return n * b + 1;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int j = Integer.parseInt(st.nextToken());
			pw.println("Case #" + t + ":");
			int m = n / 2 - 2;
			for (int i = 0; i < j; i++) {
				StringBuilder sb = new StringBuilder();
				sb.append("1");
				for (int k = 0; k < m; k++)
					sb.append((i & 1 << k) == 0 ? "0" : "1");
				sb.append("11");
				for (int k = 0; k < m; k++)
					sb.append((i & 1 << k) == 0 ? "0" : "1");
				sb.append("1");
				for (int b = 2; b <= 10; b++)
					sb.append(" " + value(i, m, b));
				pw.println(sb);
			}
		}
		pw.close();
	}
}
