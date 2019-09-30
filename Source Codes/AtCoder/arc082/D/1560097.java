import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		int x = nextInt();
		int k = nextInt();
		int[] flip = new int[k];
		for (int i = 0; i < k; i++) {
			flip[i] = nextInt();
		}
		
		int q = nextInt();
		
		Function func = new Function(x);
		
		int dir = -1;
		
		int ptr = 0;
		
		int curT = 0;
		
		while (q-- > 0) {
			int t = nextInt();
			int qx = nextInt();
			
			while (ptr < k && flip[ptr] <= t) {
				func.modify(flip[ptr] - curT, dir);
				curT = flip[ptr];
				dir *= -1;
				ptr++;
			}
			
			func.modify(t - curT, dir);
			curT = t;
			
			out.println(func.getAt(qx));
		}
	}
	
	static class Function {
		int flipX;
		int flipY;
		int len;
		
		final int X;

		public Function(int x) {
			flipX = 0;
			flipY = 0;
			len = x;
			this.X = x;
		}
		
		int getAt(int x) {
			if (x <= flipX) {
				return flipY;
			}
			if (x >= flipX + len) {
				return flipY + len;
			}
			return flipY + x - flipX;
		}
		
		void modify(int dist, int dir) {
			flipY += dist * dir;
			if (flipY + len <= 0) {
				flipX = flipY = len = 0;
				return;
			}
			if (flipY >= X) {
				flipX = len = 0;
				flipY = X;
				return;
			}
			
			if (flipY < 0) {
				int delta = -flipY;
				flipX += delta;
				len -= delta;
				flipY = 0;
				return;
			}
			if (flipY + len > X) {
				int delta = flipY + len - X;
				len -= delta;
				return;
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}