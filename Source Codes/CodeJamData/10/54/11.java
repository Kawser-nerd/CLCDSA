package gcj2010.r3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Formatter;
import java.util.Scanner;

public class D {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\2010r3\\";
	private final char CHARQ = this.getClass().getSimpleName().charAt(0);
	private final String OUTPATH = BASEPATH + CHARQ;
	private final String INPATH = BASEPATH + CHARQ + "-small-attempt0.in";
//	private final String INPATH = BASEPATH + CHARQ + "-large.in";
	
	private String INPUT = "2 2";
	private static final int MODE = 1; // 0:test, 1:single thread
	
	public Object solve() throws Exception
	{
		int n = ni();
		int b = ni();
		hist = new int[100];
		p = 0;
		return rec(n, n, b);
	}
	
	int[] hist;
	int p;
	
	private long rec(int n, int max, int b)
	{
		if(n == 0){
//			tr(Arrays.toString(hist));
			return 1;
		}
		if(max == 0)return 0;
		
		long ret = 0;
		for(int j = 1;j <= max && j <= n;j++){
			boolean g = true;
			for(int i = 0;i < p;i++){
				if(match(hist[i], j, b)){
					g = false;
					break;
				}
			}
			if(g){
				hist[p++] = j;
				ret += rec(n - j, j - 1, b);
				p--;
				hist[p] = 0;
			}
		}
		return ret % MOD;
	}
	
	long MOD = 1000000007L;
	
	private boolean match(int u, int v, int b)
	{
		for(;u > 0 && v > 0; u /= b, v /= b){
			if(u % b == v % b)return true;
		}
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
		new D().call();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private int[] ni(int n) { int[] ret = new int[n]; for(int i = 0;i < n;i++)ret[i] = ni(); return ret; }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}
