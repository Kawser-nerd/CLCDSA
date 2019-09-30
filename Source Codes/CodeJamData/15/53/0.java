import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	class O {
		int pos;
		int vel;

		public O(int pos, int vel) {
			super();
			this.pos = pos;
			this.vel = vel;
		}

	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int mySpeed = in.nextInt();
			int n = in.nextInt();
			int[] p = new int[n];
			int[] s = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = in.nextInt();
			}
			for (int i = 0; i < n; i++) {
				s[i] = in.nextInt();
			}
			ArrayList<O> left = new ArrayList<>();
			ArrayList<O> right = new ArrayList<>();
			{
				ArrayList<O> tmp = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (p[i] > 0) {
						tmp.add(new O(p[i], s[i]));
					}
				}
				Collections.sort(tmp, new Comparator<O>() {

					@Override
					public int compare(O o1, O o2) {
						return Integer.compare(o1.pos, o2.pos);
					}
				});
				for (int i = 0; i < tmp.size(); i++) {
					O cur = tmp.get(i);
					while (right.size() > 0
							&& right.get(right.size() - 1).vel <= cur.vel) {
						right.remove(right.size() - 1);
					}
					right.add(cur);
				}
			}
			{
				ArrayList<O> tmp = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (p[i] < 0) {
						tmp.add(new O(p[i], s[i]));
					}
				}
				Collections.sort(tmp, new Comparator<O>() {

					@Override
					public int compare(O o1, O o2) {
						return -Integer.compare(o1.pos, o2.pos);
					}
				});
				for (int i = 0; i < tmp.size(); i++) {
					O cur = tmp.get(i);
					while (left.size() > 0
							&& left.get(left.size() - 1).vel <= cur.vel) {
						left.remove(left.size() - 1);
					}
					left.add(cur);
				}
			}
			int cL = left.size();
			int cR = right.size();
			double[][][] dp = new double[2][cL + 1][cR + 1];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j <= cL; j++) {
					Arrays.fill(dp[i][j], Double.MAX_VALUE);
				}
			}
			for (int i = 0; i < Math.min(cL, 1); i++) {
				dp[0][i + 1][0] = -left.get(i).pos * 1.0
						/ (mySpeed - left.get(i).vel);
			}
			for (int i = 0; i < Math.min(cR, 1); i++) {
				dp[1][0][i + 1] = right.get(i).pos * 1.0
						/ (mySpeed - right.get(i).vel);
			}
			double result = Double.MAX_VALUE;
			for (int sum = 1; sum <= cL + cR; sum++) {
				for (int l = 0; l <= sum && l <= cL; l++) {
					int r = sum - l;
					if (r > cR) {
						continue;
					}
					for (int type = 0; type < 2; type++) {
						double time = dp[type][l][r];
						if (time == Double.MAX_VALUE) {
							continue;
						}
						int realL = l, realR = r;
						double pos = 0.0;
						if (type == 0) {
							pos = left.get(l - 1).pos - left.get(l - 1).vel
									* time;
							while (realL != cL
									&& left.get(realL).pos
											- left.get(realL).vel * time >= pos) {
								realL++;
							}
						}
						if (type == 1) {
							pos = right.get(r - 1).pos + right.get(r - 1).vel
									* time;
							while (realR != cR
									&& right.get(realR).pos
											+ right.get(realR).vel * time <= pos) {
								realR++;
							}
						}
						if (realL == cL && realR == cR) {
							result = Math.min(result, time);
						}
						if (realL != cL) {
							double moreTime = Math.abs(left.get(realL).pos
									- left.get(realL).vel * time - pos)
									/ (mySpeed - left.get(realL).vel + 0.);
							dp[0][realL + 1][realR] = Math.min(
									dp[0][realL + 1][realR], time + moreTime);
						}
						if (realR != cR) {
							double moreTime = Math.abs(right.get(realR).pos
									+ right.get(realR).vel * time - pos)
									/ (mySpeed - right.get(realR).vel + 0.);
							dp[1][realL][realR + 1] = Math.min(
									dp[1][realL][realR + 1], time + moreTime);
						}
					}
				}
			}
			out.println(result);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("C.in"));
			out = new PrintWriter(new File("C.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}