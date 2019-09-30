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
import java.util.Scanner;

public class A {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\r1a\\";
	private final String OUTPATH = BASEPATH + this.getClass().getSimpleName();
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName().toLowerCase() + ".in";
//	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-small-attempt0.in";
	private final String INPATH = BASEPATH + this.getClass().getSimpleName() + "-large.in";
	
	private String INPUT = "7 3 ....... ....... ....... ...R... ...BB.. ..BRB.. .RRBR..";// + U.add(new StringBuilder(), 10000000, 1000).toString();
//	private String INPUT = "6 4 ...... ...... .R...R .R..BB .R.RBR RB.BBB";// + U.add(new StringBuilder(), 10000000, 1000).toString();
	private static final int MODE = 1; // 0:test, 1:single thread
	
	public Object solve() throws Exception
	{
		int n = ni();
		int k = ni();
		char[][] m = new char[n][n];
		for(int i = 0;i < n;i++){
			String s = in.next();
			for(int j = 0;j < n;j++){
				m[i][j] = s.charAt(j);
			}
		}
		
		char[][] r = new char[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				r[i][j] = '.';
			}
		}
		for(int i = 0;i < n;i++){
			int p = n - 1;
			for(int j = n - 1;j >= 0;j--){
				if(m[i][j] == 'R' || m[i][j] == 'B'){
					r[i][p] = m[i][j];
					p--;
				}
			}
		}
		
//		tra(r);
		boolean wr = judge(r, 'R', n, k);
		boolean wb = judge(r, 'B', n, k);
		
		if(wr){
			if(wb){
				return "Both";
			}else{
				return "Red";
			}
		}else{
			if(wb){
				return "Blue";
			}else{
				return "Neither";
			}
		}
	}
	
//	int[] dx = new int[]{1, 0, -1, 0, 1, -1, -1, 1};
//	int[] dy = new int[]{0, 1, 0, -1, 1, 1, -1, -1};
	int[] dx = new int[]{1, 0, 1, -1};
	int[] dy = new int[]{0, 1, 1, 1};
	
	private boolean judge(char[][] r, char c, int n, int k)
	{
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(r[i][j] == c){
					for(int l = 0;l < 4;l++){
						int cx = i, cy = j;
						boolean f = true;
						for(int u = 2;u <= k;u++){
							cx += dx[l]; cy += dy[l];
							if(cx >= n || cx < 0 || cy >= n || cy < 0){f = false; break; }
							if(r[cx][cy] != c){f = false; break;}
						}
						if(f){
//							tr(i, j, l);
							return true;
						}
					}
				}
			}
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
		new A().call();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private int[] ni(int n) { int[] ret = new int[n]; for(int i = 0;i < n;i++)ret[i] = ni(); return ret; }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	public static void tra(int[] a) {System.out.println(Arrays.toString(a));}
	public static void tra(char[][] a){for(char[] e : a){	System.out.println(Arrays.toString(e));}}
	public static StringBuilder add(StringBuilder sb, int n){sb.append(n);sb.append(' ');return sb;}
	public static StringBuilder add(StringBuilder sb, int n, int k){for(int i = 0;i < k;i++){add(sb, n);}return sb;}
}
