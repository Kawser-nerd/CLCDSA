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

import javax.management.RuntimeErrorException;

public class B {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {
			Object o = new B().solve();

			out.println("Case #" + casito + ": " + o);
			System.out.println("Case #" + casito + ": " + o);
		}
		out.close();
	}

	private Object solve() throws Exception {
		
		int B = ni();
		long N = ni();
		
		long[] arr = nla(B);
		
		if(N <= B){
			return N;
		}
		long lo = -1;
		long hi = (long) 1e16;
		while(lo + 1L < hi){
			long m = (lo+hi)/2L;
			long aux =0;
			for(long a : arr){
				aux += m/a +1L;
			}
			if(aux >= N){
				hi = m;
			}else{
				lo = m;
			}
		}
		long complete = 0;
		for(long a : arr)
			complete+= (hi-1L)/a + 1L;
		
		long left = N - complete -1L;
		for(int i =0;i<B;i++)
			if(hi%arr[i]==0L){
				if(left ==0L)
					return i+1;
				left--;
			}
		throw new RuntimeErrorException(null);
	}

	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "B"; //
	static String loc = "/home/miguel/workspace/CodeJam/round_1A/src"; //

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