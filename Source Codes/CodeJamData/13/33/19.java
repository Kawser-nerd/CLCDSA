import java.io.*;
import java.util.*;

public class taskC {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	class Attack implements Comparable<Attack> {
		int d, l, r, s;

		public Attack(int d, int l, int r, int s) {
			this.d = d;
			this.l = l;
			this.r = r;
			this.s = s;
		}

		@Override
		public int compareTo(Attack arg0) {
			return d - arg0.d;
		}

		@Override
		public String toString() {
			return "Attack [d=" + d + ", l=" + l + ", r=" + r + ", s=" + s
					+ "]\n";
		}

	}

	public void solve() throws IOException {
		//System.err.println("--");
		int n = nextInt();
		ArrayList<Attack> ats = new ArrayList<Attack>();
		for (int i = 0; i < n; i++) {
			int d = nextInt();
			int c = nextInt();
			int l = nextInt();
			int r = nextInt();
			int s = nextInt();
			int dd = nextInt();
			int dp = nextInt();
			int ds = nextInt();
			for (int j = 0; j < c; j++) {
				ats.add(new Attack(d + j * dd, l + dp * j, r + dp * j, s + ds
						* j));
			}
		}
		Collections.sort(ats);
		//System.err.println(ats.toString());
		n = ats.size();
		int[] h = new int[1000];
		int ans = 0;
		for (int i = 0; i < n;) {
			int t = i;
			while (t < n && ats.get(t).d == ats.get(i).d)
				t++;
			for (int j = i; j < t; j++) {
			//	System.err.println(ats.get(j).d + " " + ats.get(j).l + " " +  ats.get(j).r);
				for (int k = ats.get(j).l; k < ats.get(j).r; k++) {
					if (h[k + 500] < ats.get(j).s) {
						ans++;
						break;
					}
				}
			}
			for (int j = i; j < t; j++) {
				for (int k = ats.get(j).l; k < ats.get(j).r; k++) {
					h[k + 500] = Math.max(ats.get(j).s, h[k + 500]);
				}
			}
			i = t;
		}
		out.println(ans);
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskC.in"));
			out = new PrintWriter("taskC.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {

				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskC().run();
	}
}
