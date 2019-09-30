import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	public static BufferedReader in;
	public static PrintWriter out;

	static int[][] prob;
	static int count = 1000000;

	public static void main(String... args) throws Exception {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			System.err.println("LEYENDO DE ARCHIVO");
		} catch (Exception e) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter("output.txt");

		prob = new int[1000][1000];

		for (int k = 0; k < count; k++) {
			int[] arr = new int[1000];
			for (int i = 0; i < 1000; i++)
				arr[i] = i;
			for (int i = 0; i < 1000; i++) {
				int index = (int) (Math.random() * 1000);
				int t = arr[i];
				arr[i] = arr[index];
				arr[index] = t;
			}
			for (int i = 0; i < 1000; i++)
				prob[arr[i]][i]++;
		}
		System.out.println(prob[7][234]);
		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			Object o = solve();
			out.println("Case #" + i + ": " + o);
			System.out.println("Case #" + i + ": " + o);
		}
		out.close();
	}

	private static Object solve() throws Exception {
		int same = ni();
		int[] arr = nia(1000);
		double likely = 1.0;
		for (int i = 0; i < 1000; i++) {
			double move = (prob[arr[i]][i]*1000) / (double) count;
//			System.out.println(likely);
			likely *=  move;
		}
		if (likely >1.0)
			return "BAD";
		return "GOOD";
	}

	static StringTokenizer strTok = new StringTokenizer("");

	static String nextToken() throws IOException {
		while (!strTok.hasMoreTokens())
			strTok = new StringTokenizer(in.readLine());
		return strTok.nextToken();
	}

	static int ni() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nl() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nd() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int[] nia(int size) throws IOException {
		int[] ret = new int[size];
		for (int i = 0; i < size; i++)
			ret[i] = ni();
		return ret;
	}

	static long[] nla(int size) throws IOException {
		long[] ret = new long[size];
		for (int i = 0; i < size; i++)
			ret[i] = nl();
		return ret;
	}

	static double[] nda(int size) throws IOException {
		double[] ret = new double[size];
		for (int i = 0; i < size; i++)
			ret[i] = nd();
		return ret;
	}

}
