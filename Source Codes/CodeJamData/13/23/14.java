import java.io.*;
import java.util.*;

public class Garbled {
	public static void main(String[] args) {
		new Garbled().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	String FNAME = "c";

	private void solve() throws IOException {
		Scanner in = new Scanner(new File("garbled_email_dictionary.txt"));
		ArrayList<String> words = new ArrayList<String>();
		while (in.hasNext()) {
			words.add(in.next());
		}
		in.close();
		System.err.println("Words found: " + words.size());
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + (test) + ": ");
			char[] text = nextToken().toCharArray();
			int[][] a = new int[text.length + 1][5];
			for (int i = 0; i < a.length; i++) {
				Arrays.fill(a[i], Integer.MAX_VALUE / 4);
			}
			a[0][4] = 0;
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] >= Integer.MAX_VALUE / 4) {
						continue;
					}
					for (String s : words) {
						if (s.equals("code") || s.equals("jam")) {
							i += 0;
						}
						match(text, i, s, j);
						if (i + s.length() < a.length
								&& a[i + s.length()][Math.min(last, 4)] > a[i][j]
										+ cnt) {
							a[i + s.length()][Math.min(last, 4)] = a[i][j]
									+ cnt;
						}
					}
				}
			}
			int ans = Integer.MAX_VALUE / 4;
			for (int i = 0; i < a[text.length].length; i++) {
				ans = Math.min(ans, a[text.length][i]);
			}
			out.println(ans);
		}
	}

	int last, cnt;

	private void match(char[] a, int i, String s, int j) {
		if (i + s.length() - 1 >= a.length) {
			cnt = Integer.MAX_VALUE / 4;
			return;
		}
		last = j;
		cnt = 0;
		for (int k = 0; k < s.length(); k++) {
			if (a[i + k] == s.charAt(k)) {
				last++;
			} else {
				if (last < 4) {
					cnt = Integer.MAX_VALUE / 4;
					return;
				}
				cnt++;
				last = 0;
			}
		}
	}
}
