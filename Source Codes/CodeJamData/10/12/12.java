package gcj2010.r1a;

import gcj2010.U;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Formatter;
import java.util.Scanner;

public class B {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\r1a\\";
	private final String OUTPATH = BASEPATH + this.getClass().getSimpleName();
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName().toLowerCase() + ".in";
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-small-attempt2.in";
	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-large.in";
	
	private String INPUT = "6 6 2 100 " + U.add(new StringBuilder(), 5, 100).toString();
//	private String INPUT = "100 1 5 3 1 50 7";// + U.add(new StringBuilder(), 10000000, 1000).toString();
	private static final int MODE = 1; // 0:test, 1:single thread
	
	private long[][] cache;
	
	public Object solve() throws Exception
	{
		int d = ni();
		int ii = ni();
		int m = ni();
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		
		cache = new long[257][100];
		for(int i = 0;i < 257;i++){
			for(int j = 0;j < 100;j++){
				cache[i][j] = Long.MAX_VALUE;
			}
		}
		return rec(a, 256, 0, d, ii, m, n);
	}
	
	private long rec(int[] a, int prev, int pos, int d, int ii, int m, int n)
	{
		if(pos == n)return 0;
		if(cache[prev][pos] != Long.MAX_VALUE)return cache[prev][pos];
		long min = d + rec(a, prev, pos + 1, d, ii, m, n); // delete
		for(int i = 0;i <= 255;i++){
			long v = Math.abs(a[pos] - i) + (prev < 256 ? inp(prev, i, ii, m) : 0) + rec(a, i, pos + 1, d, ii, m, n);
			if(v < min)min = v;
		}
		cache[prev][pos] = min;
		return min;
	}
		
	private int inp(int a, int b, int ii, int m){
		if(a == b)return 0;
		if(m == 0)return 99999;
		return (int)((Math.abs(b - a) - 1) / m) * ii;
	}
	
	private Scanner in;
	
	public void call() throws Exception
	{
		long start = System.currentTimeMillis();
		if(MODE > 0){
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(INPATH)));
			Scanner sc = new Scanner(br);
			int n = sc.nextInt();
			sc.nextLine();
			
			this.in = sc;
			Formatter fmt = new Formatter();
			for(int i = 0;i < n;i++){
				Object result = solve();
				fmt.format("Case #%d: %s\n", i + 1, result);
				System.out.println("case " + (i + 1) + " solved.\t" + result);
			}
			
			BufferedWriter bw = null;
			try {
				String f = OUTPATH + SDF.format(new Date()) + ".txt";
				bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));
				bw.write(fmt.toString());
				System.out.println("out " + f);
			}catch(Exception e){
			}finally{
				if(bw != null)bw.close();
			}
			
		}else{
			in = new Scanner(INPUT);
			System.out.println(solve());
		}
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().call();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private int[] ni(int n) { int[] ret = new int[n]; for(int i = 0;i < n;i++)ret[i] = ni(); return ret; }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	public static void tra(int[] a) {System.out.println(Arrays.toString(a));}
	public static void tra(int[][] a){for(int[] e : a){	System.out.println(Arrays.toString(e));}}
	public static StringBuilder add(StringBuilder sb, int n){sb.append(n);sb.append(' ');return sb;}
	public static StringBuilder add(StringBuilder sb, int n, int k){for(int i = 0;i < k;i++){add(sb, n);}return sb;}
}
