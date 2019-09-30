import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	final static int modulo = 10009;
	
	char[] s;
	int k, n;
	int[][] chars;
	int[] current;
	int[] result;

	private void solve() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("b.in"));
		PrintWriter pw = new PrintWriter("b.out");
		
		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = (st.nextToken() + "+").toCharArray();
			k = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(br.readLine());
			chars = new int[n][26];
			for (int i = 0; i < n; i++) {
				String str = br.readLine();
				Arrays.fill(chars[i], 0);
				for (int j = 0; j < str.length(); j++) {
					chars[i][str.charAt(j) - 'a']++;
				}
			}
			
			result = new int[k];
			Arrays.fill(result, 0);
			current = new int[26];
			Arrays.fill(current, 0);
			go(0);
			
			pw.print("Case #" + test + ":");
			for (int i = 0; i < k; i++) {
				pw.print(" " + result[i]);
			}
			pw.println();
		}
		
		br.close();
		pw.close();
	}

	private void go(int t) {
		if (t > 0) {
			check(t);
		}
		if (t == k) {
			return;
		}
		
		for (int i = 0; i < n; i++) {
			for (int c = 0; c < 26; c++) {
				current[c] += chars[i][c];
			}
			go(t + 1);
			for (int c = 0; c < 26; c++) {
				current[c] -= chars[i][c];
			}
		}
	}

	private void check(int t) {
		int all = 0;
		int cur = 1;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '+') {
				all = (all + cur) % modulo;
				cur = 1;
			} else {
				cur = (cur * current[s[i] - 'a']) % modulo;
			}
		}
		result[t - 1] = (result[t - 1] + all) % modulo;
	}

}
