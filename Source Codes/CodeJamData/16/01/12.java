import java.io.*;

public class A {
	static void mark(boolean[] bb, int n) {
		if (n > 0) {
			bb[n % 10] = true;
			mark(bb, n / 10);
		}
	}
	static boolean check(boolean[] bb) {
			for (int d = 0; d <= 9; d++)
				if (!bb[d])
					return false;
			return true;
	}
	static int count(int n) {
		boolean[] bb = new boolean[10];
		for (int i = 1; ; i++) {
			mark(bb, n * i);
			if (check(bb))
				return n * i;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			pw.println("Case #" + t + ": " + (n == 0 ? "INSOMNIA" : count(n)));
		}
		pw.close();
	}
}
