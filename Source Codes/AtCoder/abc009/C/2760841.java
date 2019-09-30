import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	// Build least lexographical greedy!

	public static int count(char a[],char b[]) {
		int cnt = 0;
		for (int i = 0 ; i < a.length ; ++i) {
			cnt += a[i] != b[i] ? 1 : 0;
		}
		return cnt;
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		char s[] = sc.next().toCharArray();
		int cnt[] = new int[26];
		for (int i = 0 ; i < n ; ++i) {
			++cnt[s[i] - 'a'];
		}
		char ans[] = new char[n];
		for (int i = 0 ; i < n ; ++i) {
			for (int c = 0; c < 26 ; ++c) {
				if (cnt[c] > 0) {
					int tmp[] = new int[26];
					for (int j = 0 ; j < 26 ; ++j) {
						tmp[j] = cnt[j];
					}
					--tmp[c];
					char cur[] = new char[n];
					Arrays.fill(cur, '?');
					for (int j = 0 ; j < i ; ++j) {
						cur[j] = ans[j];
					}
					cur[i] = (char)(c + 'a');
					for (int j = i + 1 ; j < n ; ++j) {
						if (tmp[s[j] - 'a'] > 0) {
							tmp[s[j] - 'a']--;
							cur[j] = s[j];
						}
					}
					if (count(s,cur) <= k) {
						ans[i] = (char)(c + 'a');
						--cnt[c];
						break;
					}
				}
			}
		}
		for (int i = 0 ; i < n ; ++i) {
			System.out.print(ans[i]);
		}
		System.out.println("");


	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}