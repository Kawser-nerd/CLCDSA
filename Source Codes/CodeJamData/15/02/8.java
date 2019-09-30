import java.io.*;
import java.util.*;

class Pancakes {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] aa = new int[n];
			int amax = 0;
			for (int i = 0; i < n; i++) {
				aa[i] = Integer.parseInt(st.nextToken());
				if (amax < aa[i])
					amax = aa[i];
			}
			int min = Integer.MAX_VALUE;
			for (int a = 1; a <= amax; a++) {
				int cnt = a;
				for (int i = 0; i < n; i++)
					if (aa[i] > a)
						cnt += aa[i] / a - (aa[i] % a == 0 ? 1 : 0);
				if (min > cnt)
					min = cnt;
			}
			pw.println("Case #" + t + ": " + min);
		}
		pw.close();
	}
}
