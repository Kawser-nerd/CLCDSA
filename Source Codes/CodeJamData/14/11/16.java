import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static BufferedReader in;
	public static PrintWriter out;

	public static void main(String... args) throws Exception {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			System.err.println("LEYENDO DE ARCHIVO");
		} catch (Exception e) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter("output.txt");

		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			Object o = solve();
			out.println("Case #" + i + ": " + o);
			System.out.println("Case #" + i + ": " + o);
		}
		out.close();
	}

	private static Object solve() throws Exception {
		int N = ni();
		int L = ni();

		long[] initial = new long[N];
		long[] req = new long[N];

		String[] line= in.readLine().split(" ");
		for(int i =0;i<N;i++)
			initial[i]= Long.parseLong(line[i], 2);
		
		line= in.readLine().split(" ");
		for(int i =0;i<N;i++)
			req[i]= Long.parseLong(line[i], 2);
		
		Arrays.sort(req);
		int ret = Integer.MAX_VALUE;
		for(int i =0;i<N;i++){
			long change = initial[i] ^ req[0];
			long[] result = new long[N];
			for(int j =0;j<N;j++)
				result[j]= change ^ initial[j];
			Arrays.sort(result);
			if(Arrays.equals(req, result)){
				ret = Math.min(ret, Long.bitCount(change));
			}
		}
		if(ret==Integer.MAX_VALUE)
			return "NOT POSSIBLE";
		return ret;
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
