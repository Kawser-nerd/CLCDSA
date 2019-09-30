package gcj2010.r1a;

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
import java.util.HashMap;
import java.util.Scanner;

public class C {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\r1a\\";
	private final String OUTPATH = BASEPATH + this.getClass().getSimpleName();
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName().toLowerCase() + ".in";
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-small-attempt0.in";
	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-large.in";
	
	private String INPUT = "1 999999 1 999999";// + U.add(new StringBuilder(), 10000000, 1000).toString();
	private static final int MODE = 1; // 0:test, 1:single thread
	
	private HashMap<Long, Boolean> cache;
	
	public Object solve() throws Exception
	{
		long a1 = ni();
		long a2 = ni();
		long b1 = ni();
		long b2 = ni();
		cache = new HashMap<Long, Boolean>();
		
		long ret = 0;
		for(long a = a1;a <= a2;a++){
			long sup = (int)(Math.floor((Math.sqrt(5) + 1) / 2 * a));
			long inf = (int)(Math.ceil((Math.sqrt(5) - 1) / 2 * a));
			if(sup >= b1 && inf <= b2){
				ret += Math.min(sup, b2) - Math.max(inf, b1) + 1;
			}
//			for(int b = b1;b <= b2;b++){
//				if(rec(a, b)){
//					tr(a, b);
//					ret++;
//				}
//			}
		}
		
		return (b2 - b1 + 1) * (a2 - a1 + 1) - ret;
	}
	
	// a>b
	private boolean rec(int a, int b)
	{
		if(a < b){int d = a; a = b; b = d;}
		
		long code = ((long)b << 21) | (long)a;
		if(cache.containsKey(code))return cache.get(code);
		if(a / b >= 2)return true;
		int lim = a / b;
		for(int k = 1;k <= lim;k++){
			if(a - k * b == 0)continue;
			if(!rec(a - k * b, b)){
				cache.put(code, true);
				return true;
			}
		}
		cache.put(code, false);
		return false;
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
		new C().call();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private int[] ni(int n) { int[] ret = new int[n]; for(int i = 0;i < n;i++)ret[i] = ni(); return ret; }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	public static void tra(int[] a) {System.out.println(Arrays.toString(a));}
	public static void tra(int[][] a){for(int[] e : a){	System.out.println(Arrays.toString(e));}}
	public static StringBuilder add(StringBuilder sb, int n){sb.append(n);sb.append(' ');return sb;}
	public static StringBuilder add(StringBuilder sb, int n, int k){for(int i = 0;i < k;i++){add(sb, n);}return sb;}
}
