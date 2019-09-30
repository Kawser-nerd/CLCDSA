import java.util.*;
import java.io.*;

public class Main {
	
	int max;

	class Data {
		int leftX, rightX;
		int leftConst, rightConst;
		
		public Data(int leftX, int rightX, int leftConst, int rightConst) {
			this.leftX = leftX;
			this.rightX = rightX;
			this.leftConst = leftConst;
			this.rightConst = rightConst;
		}
		
		int get(int x) {
			if (x <= leftX) {
				return leftConst;
			} else if (x >= rightX) {
				return rightConst;
			} else {
				return leftConst + (x - leftX);
			}
		}
		
		Data up(int value) {
			if (leftConst + value >= max) {
				return new Data(0, 0, max, max);
			} else if (rightConst + value >= max) {
				int diff = rightConst + value - max;
				return new Data(leftX, rightX - diff, leftConst + value, max);
			} else {
				return new Data(leftX, rightX, leftConst + value, rightConst + value);
			}
		}
		
		Data down(int value) {
			if (rightConst - value <= 0) {
				return new Data(0, 0, 0, 0);
			} else if (leftConst - value <= 0) {
				int diff = value - leftConst;
				return new Data(leftX + diff, rightX, 0, rightConst - value);
			} else {
				return new Data(leftX, rightX, leftConst - value, rightConst - value);
			}
		}
	}
	
	void solve() {
		max = in.nextInt();
		int k = in.nextInt();
		int[] r = new int[k + 1];
		for (int i = 0; i < k; i++) {
			r[i] = in.nextInt();
		}
		r[k] = (int) 1e9;
		
		
		int q = in.nextInt();
		int[] t = new int[q], a = new int[q];
		for (int i = 0; i < q; i++) {
			t[i] = in.nextInt();
			a[i] = in.nextInt();
		}
		Data cur = new Data(0, max, 0, max);
		
		int ptr = 0;
		for (int i = 0; i < r.length; i++) {
			int prevTime = i == 0 ? 0 : r[i - 1];
			while (ptr < q && t[ptr] <= r[i]) {
				int diff = t[ptr] - prevTime;
				Data ans = null;
				if (i % 2 == 1) {
					ans = cur.up(diff);
				} else {
					ans = cur.down(diff);
				}
				out.println(ans.get(a[ptr++]));
			}
			int diff = r[i] - prevTime;
			prevTime = r[i];
			if (i % 2 == 1) {
				cur = cur.up(diff);
			} else {
				cur = cur.down(diff);
			}
		}
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}