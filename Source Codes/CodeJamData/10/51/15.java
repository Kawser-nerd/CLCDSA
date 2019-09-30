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
import java.util.HashSet;
import java.util.Scanner;

public class A {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\2010r3\\";
	private final char CHARQ = this.getClass().getSimpleName().charAt(0);
	private final String OUTPATH = BASEPATH + CHARQ;
//	private final String INPATH = BASEPATH + CHARQ + "-small-attempt4.in";
	private final String INPATH = BASEPATH + CHARQ + "-large.in";
	
//	private String INPUT = "2 10 0 1 2 3 4 5 6 7 8 9";
//	private String INPUT = "4 10 1 0 1 0 1 0 1 0 1 0";
//	private String INPUT = "1 3 0 6 6";
	private String INPUT = "1 5 6 6 6 6 6";
//	private String INPUT = "4 9 12 2 37 21 6 23 70 12 2";
//	private String INPUT = "1 6 5 4 3 2 1 0";
	private static final int MODE = 1; // 0:test, 1:single thread
	
	static int pn = 1000000;
	static ArrayList<Integer> primes;
	static {
		primes = new ArrayList<Integer>();
		
		boolean[] p = new boolean[pn+1];
		for(int i = 2;i <= pn;i++){
			if(!p[i]){
				primes.add(i);
				for(int j = i + i;j <= pn;j+=i){
					p[j] = true;
				}
			}
		}
	}
	
	public Object solve() throws Exception
	{
		int d = ni();
		int k = ni();
		int[] s = ni(k);
		
		if(k == 2 && s[0] == s[1])return s[1];
		if(k <= 2)return "I don't know.";
		
		int max = 0;
		for(int u : s)if(u > max)max = u;
		
		int d10 = (int)Math.pow(10, d);
		
//		System.out.println(primes);
		int nex = -1;
		for(int p : primes){
			if(p > d10)break;
			if(p <= max)continue;
			
			int prev = -1;
			for(int i = 0;i < s.length - 2;i++){
				int ss = (s[i+1] - s[i] + p) % p;
				int next;
				if(ss == 0){
					next = s[i];
				}else{
					int tt = (s[i+2] - s[i+1] + p) % p;
					if(tt == 0){
						next = s[k - 1];
					}else{
						int[] e = exGCD(ss, p);
	//					tr(ss, e[0], e[1], e[2], p, (e[1] * ss) % p);
						long a = ((long)e[1] * (long)tt) % p;
						next = (int)((a * (s[k - 1] - s[k - 2]) + s[k-1]) % p);
						next = (next + p) % p;
					}
				}
				if(prev == -1 || prev == next){
//					tr(prev, next);
					prev = next;
				}else{
					prev = -1;
					break;
				}
			}
			
			if(prev != -1){
				if(nex == -1 || nex == prev){
//					tr(p, prev);
					nex = prev;
				}else{
					return "I don't know.";
				}
			}
		}
		if(nex == -1){
			return "I don't know.";
		}
		
		return nex;
	}
	
	private int[] exGCD(int a, int b)
	{
		int p = 1, q = 0;
		int r = 0, s = 1;
		while(b > 0){
			int c = a / b;
			int d = a;
			a = b;
			b = d % b;
			
			d = p; p = q; q = d - c * q;
			d = r; r = s; s = d - c * s;
		}
		return new int[]{a, p, r};
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
		new A().call();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private int[] ni(int n) { int[] ret = new int[n]; for(int i = 0;i < n;i++)ret[i] = ni(); return ret; }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}
