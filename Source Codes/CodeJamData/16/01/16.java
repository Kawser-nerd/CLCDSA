import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {
			Object o = new A().solve();

			out.println("Case #" + casito + ": " + o);
			System.out.println("Case #" + casito + ": " + o);
		}
		out.close();
	}

	private Object solve() throws Exception {
//		int N = 1000000;
//		long[] arr = new long[N+1];
//		for(int i = 1; i<=N;i++){
//			arr[i] = obtain(i);
//		}
//		long sum = 0;
//		long max = 0;
//		for(long a : arr) {
//			sum += (long) (a);
//			max = Math.max(max, a);
//		}
//		System.out.println(sum);
//		System.out.println(max);
		
		long n = Integer.parseInt(in.readLine());
		if(n == 0L){
			return "INSOMNIA";
		}

		return n * obtain(n);
	}

	private int obtain(long i) {
		int res = 1;
		boolean[] ok = new boolean[10];
		while(true){
			String s = Long.toString(i * res);
			for(int j =0 ;j<s.length();j++){
				ok[s.charAt(j)-'0'] = true;
			}
			boolean all = true;
			for(boolean b : ok) 
				all = all && b;
			if(all)
				return res;
			res++;
		}
	}
	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "A"; //
	static String loc = "/home/miguel/workspace/CodeJam/qualy2016/src"; //

	static void configure() throws Exception {

		File file = new File(loc);
		File[] paths = file.listFiles();
		List<File> input = new ArrayList<File>();
		for (File f : paths) {
			String s = f.getName();
			if (s.startsWith(name_class) && s.endsWith(".in"))
				input.add(f);
		}

		if (input.isEmpty()) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		} else {
			File last_file = input.get(0);
			for (File f : input) {
				if (f.lastModified() > last_file.lastModified())
					last_file = f;
			}

			in = new BufferedReader(new FileReader(last_file.toString()));
			System.err.println("LEYENDO DE ARCHIVO");

		}
		FileWriter fw = new FileWriter(loc + "/output.txt");
		out = new PrintWriter(fw);

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