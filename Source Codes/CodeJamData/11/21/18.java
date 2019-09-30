import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class first {
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
		String gm[] = new String[n];
		double kilk[] = new double[n];
		double win[] = new double[n];
		double wp[] = new double[n];
		double owp[] = new double[n];
		double oowp[] = new double[n];
		for (int i = 0; i < n; i++)
			gm[i] = next();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (gm[i].charAt(j) != '.') {
					kilk[i]++;
					win[i] += gm[i].charAt(j) - '0';
				}
			wp[i] = win[i] / kilk[i];
		}
		for (int i = 0; i < n; i++) {
			double count = 0;
			for (int j = 0; j < n; j++)
				if (gm[j].charAt(i) != '.') {
					count++;
					owp[i] += (win[j] - gm[j].charAt(i) + '0') / (kilk[j] - 1);
				}
			owp[i] /= count;
		}
		for (int i = 0; i < n; i++) {
			double count = 0;
			for (int j = 0; j < n; j++)
				if (gm[i].charAt(j) != '.') {
					count++;
					oowp[i] += owp[j];
				}
			oowp[i] /= count;
		}
		for (int i = 0; i < n; i++)
			out.printf("%.9f\n", wp[i]/4+owp[i]/2+oowp[i]/4);

	};

	void run() throws IOException {
		Locale.setDefault(Locale.US);
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #" + (i +1)+ ":");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new first().run();
	}

}
