import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class SolD {

	public static void main(String[] args) {
		try {
			new SolD().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine(), " \n\t/");
			} catch (IOException e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() {
		return Long.parseLong(nextToken());
	}
	
	String FNAME = "D-small-attempt0";

    void bt(int mask, int n, int m, int acc) {
        if (n == 1) {
            int c = acc + count(mask);
            if (c > ans) {
                ans = c;
                cnt = 1;
            } else if (c == ans) {
                cnt++;
            }
        } else {
            for (int i = 1; i < (1 << m); i++) {
                if ((i & mask) == i && (i != mask)) {
                    bt(mask ^ i, n - 1, m, acc + count(i));
                }
            }
        }
    }

    class Node {
        TreeMap<Character, Node> next = new TreeMap<Character, Node>();
    }

    int count(int m) {
        if (dp[m] != -1) return dp[m];
        int n = s.length;
        Node start = new Node();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if ((m & (1 << i)) != 0) {
                Node a = start;
                for (int j = 0; j < s[i].length; j++) {
                    if (!a.next.containsKey(s[i][j])) {
                        a.next.put(s[i][j], new Node());
                        ans++;
                    }
                    a = a.next.get(s[i][j]);
                }
            }
        }
        return ans;
    }

    int[] dp;

    char[][] s;
    int ans;
    int cnt;
	
	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
            int m = nextInt();
            int n = nextInt();
            s = new char[m][];
            for (int i = 0; i < m; i++) {
                s[i] = nextToken().toCharArray();
            }
            ans = 0;
            cnt = 0;
            dp = new int[1 << m];
            Arrays.fill(dp, -1);
            bt((1 << m) - 1, n, m, 0);
            out.println(ans + " " + cnt);
        }
	}
}
