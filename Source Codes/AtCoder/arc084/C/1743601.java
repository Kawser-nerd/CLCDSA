import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		int num = nextInt();
		int len = nextInt();
		if (num % 2 == 0) {
			out.print(num / 2 + " ");
			for (int i = 0; i < len - 1; i++) {
				out.print(num + " ");
			}
			out.println();
			return;
		}

		if (num == 1) {
			int outp = (len + 1) / 2;
			for (int i = 0; i < outp; i++) {
				out.print("1 ");
			}
			out.println();
			return;
		}

		int[] a = new int[len];
		Arrays.fill(a, (num + 1) / 2);

		int nowLen = len;

		int decr = len / 2;

		while (decr > 0) {
			if (nowLen == len) {
				if (a[len - 1] - 1 >= decr) {
					a[len - 1] -= decr;
					break;
				}
				nowLen -= 1;
				decr -= a[len - 1];
			} else {
				decr--;
				if (a[nowLen - 1] == 1) {
					nowLen--;
				} else {
					a[nowLen - 1]--;
					for (int j = nowLen; j < len; j++) {
						a[j] = num;
					}
					nowLen = len;
				}
			}
		}

		for (int i = 0; i < nowLen; i++) {
			out.print(a[i] + " ");
		}
		out.println();

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
		// stress();
		// test();
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