import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class SolC {

	public static void main(String[] args) {
		try {
			new SolC().run();
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
	
	String FNAME = "C-large";

    class Rect {
        int x1, y1, x2, y2;

        Rect() {
            x1 = nextInt();
            y1 = nextInt();
            x2 = nextInt() + 1;
            y2 = nextInt() + 1;
        }
    }

    int dist(Rect a, Rect b) {
        if (b.x1 < a.x1) {
            Rect t = a; a = b; b = t;
        }
        if (a.x2 <= b.x1) {
            if (b.y1 >= a.y2) {
                return Math.max(b.x1 - a.x2, b.y1 - a.y2);
            }
            if (a.y1 >= b.y2) {
                return Math.max(b.x1 - a.x2, a.y1 - b.y2);
            }
            return b.x1 - a.x2;
        }
        if (b.y1 >= a.y2) {
            return b.y1 - a.y2;
        }
        return a.y1 - b.y2;
    }

	void solve() {
		int tests = nextInt();
        long time = System.currentTimeMillis();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
            System.err.println("Test: " + test + " " + (System.currentTimeMillis() - time));
            int w = nextInt();
            int h = nextInt();
            int n = nextInt();
            Rect[] r = new Rect[n];
            for (int i = 0; i < n; i++) {
                r[i] = new Rect();
            }

            int[][] d = new int[n + 2][n + 2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int t = dist(r[i], r[j]);
                    d[i][j] = t;
                    d[j][i] = t;
                }
                d[i][n] = r[i].x1;
                d[n][i] = d[i][n];
                d[i][n + 1] = w - r[i].x2;
                d[n + 1][i] = d[i][n + 1];
            }
            d[n][n + 1] = w;
            d[n + 1][n] = w;

            n += 2;
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }

            out.println(d[n - 2][n - 1]);
        }
	}
}
