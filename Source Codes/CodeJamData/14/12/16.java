import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

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
		List<Integer>[] g = (List<Integer>[]) new List[n];
		for(int i =0;i<n;i++)
			g[i]= new ArrayList<Integer>();
		for(int i =0;i<n-1;i++){
			int u = ni()-1;
			int v = ni()-1;
			g[u].add(v);
			g[v].add(u);
		}
		int[][] dp = new int[n][];
		for(int i =0;i<n;i++){
			dp[i]= new int[n+1];
			Arrays.fill(dp[i], -1);
		}
		int ret =1;
		for(int u =0;u<n;u++)
			ret = Math.max(go(g,dp,u,n),ret);
		
		return n-ret;
	}

	private static int go(List<Integer>[] g, int[][] dp, int u, int forb) {
		if(dp[u][forb]!=-1)
			return dp[u][forb];
		dp[u][forb]=1;
		List<Integer>  list = new ArrayList<Integer>();
		for(int v : g[u])
			if(v!=forb)
				list.add(go(g,dp,v,u));
		Collections.sort(list);
		if(list.size()>1){
			int k = list.size();
			dp[u][forb]=1+ list.get(k-1)+ list.get(k-2);
		}
		
		return dp[u][forb];
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
