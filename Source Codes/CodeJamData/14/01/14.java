import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	public static BufferedReader in;
	public static PrintWriter out;

	public static void main(String... args)  throws Exception {
		long start = System.currentTimeMillis();
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
			Object o =solve();
			out.println("Case #" + i + ": " + o);
			System.out.println("Case #" + i + ": " + o);
		}
		out.close();
		System.err.println(System.currentTimeMillis() - start);
	}

	private static Object solve() throws Exception {
		TreeSet<Integer> first = move();
		TreeSet<Integer> second= move();
		
		first.retainAll(second);
		if(first.size()==0)
			return "Volunteer cheated!";
		if(first.size()>1)
			return "Bad magician!";
		
		return first.pollFirst();
	}

	private static TreeSet<Integer> move() throws Exception {
		int row = ni();
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int i =1;i<=4;i++)
			if(i==row){
				int[] arr = nia(4);
				for(int a : arr)
					set.add(a);
			}else{
				in.readLine();
			}
		return set;
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
