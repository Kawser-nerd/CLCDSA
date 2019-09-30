import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class BaiB {

	static final int MOD = 10009;

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int ntest = sc.nextInt();
		System.out.println(ntest);
		for (int test = 1; test <= ntest; ++test) {
			System.out.println(test);
			String bt = sc.next();
			int k = sc.nextInt();
			int n = sc.nextInt();
			int[][] count = new int[n][26];
			for (int i = 0; i < n; ++i) {
				String s = sc.next();
				for (int j = 0; j < s.length(); ++j)
					count[i][s.charAt(j) - 'a']++;
			}
			String[] tmp = bt.split("[+]");
			long[] F = new long[k + 1];
			for (int i = 0; i < tmp.length; ++i) {
				long[] G = process(tmp[i].toCharArray(), count, k);
				for (int j = 1; j <= k; ++j)
					F[j] = (F[j] + G[j]) % MOD;
			}
			pw.print("Case #" + test + ":");
			for (int i = 1; i <= k; ++i)
				pw.print(" " + F[i]);
			pw.println();
		}

		sc.close();
		pw.close();
	}

	static long[] process(char[] a, int[][] count, int k) {
		int n = a.length;
		long[][] F = new long[k + 1][1 << n];
		F[0][0] = 1;

		for (int d = 1; d <= k; ++d) {
			for (int t = 0; t < count.length; ++t) {
				long[] add = new long[n];
				for (int i = 0; i < n; ++i)
					add[i] = count[t][a[i] - 'a'];
				long[] nhan = new long[1 << n];
				for (int bit = 0; bit < 1 << n; ++bit) {
					nhan[bit] = 1;
					for (int i = 0; i < n; ++i)
						if ((bit & (1 << i)) != 0)
							nhan[bit] *= add[i];
					nhan[bit] %= MOD;
				}
				for (int bit = 0; bit < 1 << n; ++bit) {
					for (int z = 0; z < 1 << n; ++z)
						if ((bit & z) == z) {
							F[d][bit] = (F[d][bit] + F[d - 1][bit ^ z] * nhan[z]) % MOD;
						}
				}
			}
		}
		long[] res = new long[k + 1];
		for (int i = 0; i <= k; ++i) {
			res[i] = (res[i] + F[i][(1 << n) - 1]) % MOD;
		}
		return res;
	}
}