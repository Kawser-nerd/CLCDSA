import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	public static BufferedReader in;
	public static PrintWriter out;

	public static void main(String... args)  throws Exception {
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
	}

	private static Object solve()  throws Exception {
		int n = ni();
		double[] naomi = nda(n);		
		double[] ken = nda(n);
		
		return deceitful(naomi,ken)+" "+regular(naomi,ken);
	}

	private static int regular(double[] naomi, double[] ken) {
		TreeSet<Double> set_naomi = parse_set(naomi);
		TreeSet<Double> set_ken = parse_set(ken);
		int ret=0;
		while(!set_naomi.isEmpty()){
			Double high = set_ken.ceiling(set_naomi.pollLast());
			if(high==null){
				set_ken.pollFirst();
				ret++;
			}else{
				set_ken.remove(high);
			}
		}
		return ret;
	}

	private static TreeSet<Double> parse_set(double[] arr) {
		TreeSet<Double> ret=new TreeSet<Double>();
		for(double d : arr)
			ret.add(d);
		return ret;
	}

	private static int deceitful(double[] naomi, double[] ken) {
		LinkedList<Double> list_naomi = parse(naomi);
		LinkedList<Double> list_ken = parse(ken);
		
		int ret=0;
		while(!list_naomi.isEmpty()){
			if(list_naomi.pollFirst()< list_ken.getFirst()){
				list_ken.pollLast();
			}else{
				ret++;
				list_ken.pollFirst();
			}
		}
		return ret;
	}


	private static LinkedList<Double> parse(double[] arr) {
		Arrays.sort(arr);
		LinkedList<Double> list = new LinkedList<Double>();
		for(double d : arr)
			list.add(d);
		return list;
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
