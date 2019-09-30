import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class second {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	};

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	};

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	};

	long nextLong() throws IOException {
		return Long.parseLong(next());
	};

	void solve() throws IOException {
		int n = nextInt();
		double d = nextDouble();
		double kor[] = new double[n];
		int kilk[] = new int[n];
		double l = 0;
		double r = 0;
		for (int i = 0; i < n; i++) {
			kor[i] = nextDouble();
			kilk[i] = nextInt();
			r += kilk[i];
		}
		double x;
		boolean flag;
		double free;
		double pos;
		r = 88 * r * r * d;
		for (int iter = 0; iter <= 170; iter++) {
			x = (l + r) / 2;
			free = Double.NEGATIVE_INFINITY;
			flag = true;
			for (int i = 0; i < n; i++) {
				if (!flag)
					break;
				for (int j = 0; j < kilk[i]; j++) {
					pos = Math.max(free, kor[i] - x);
					if (pos - kor[i] > x - 1e-10) {
						flag = false;
						break;
					}
					free = pos + d;
				}
			}
			if (flag) r=x;
			else l=x;
		}
		out.printf("%.9f\n", l);

	}

	void run() throws IOException {
		Locale.setDefault(Locale.US);
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new second().run();
	}

}
