package gcj2010.r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.math.MathContext;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Formatter;
import java.util.Scanner;

public class D {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\r2\\";
	private final char CHARQ = this.getClass().getSimpleName().charAt(0);
	private final String OUTPATH = BASEPATH + CHARQ;
	private final String INPATH = BASEPATH + CHARQ + "-small-attempt1.in";
//	private final String INPATH = BASEPATH + CHARQ + "-large.in";
	
	private String INPUT = "2 3 0 20 20 0 -20 10 40 20 -20 40";// + U.add(10000000, 1000);
	private static final int MODE = 1; // 0:test, 1:single thread
	
	public Object solve() throws Exception
	{
		int n = ni();
		int m = ni();
		int[] px = new int[n];
		int[] py = new int[n];
		int[] qx = new int[m];
		int[] qy = new int[m];
		
		for(int i = 0;i < n;i++){
			px[i] = ni();
			py[i] = ni();
		}
		for(int i = 0;i < m;i++){
			qx[i] = ni();
			qy[i] = ni();
		}
		
		double p0p1 = Math.sqrt((px[0] - px[1]) * (px[0] - px[1]) + (py[0] - py[1]) * (py[0] - py[1]));
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < m;i++){
			double p0q = Math.sqrt((px[0] - qx[i]) * (px[0] - qx[i]) + (py[0] - qy[i]) * (py[0] - qy[i]));
			double p1q = Math.sqrt((px[1] - qx[i]) * (px[1] - qx[i]) + (py[1] - qy[i]) * (py[1] - qy[i]));
			sb.append(sss(p0q, p1q, p0p1).round(new MathContext(20)).toString());
			sb.append(' ');
		}
		return sb.toString();
	}
	
	private BigDecimal sss(double a, double b, double c)
	{
		double t = (a + b + c) / 2;
		double S = Math.sqrt((t-a)*(t-b)*(t-c)*t);
		double h = 2*S/c;
		double ta = h>=a ? Math.PI/2 : (b*b<=a*a+c*c ? Math.asin(h/a) : Math.PI - Math.asin(h/a));
		double tb = h>=b ? Math.PI/2 : (a*a<=b*b+c*c ? Math.asin(h/b) : Math.PI - Math.asin(h/b));
		double sss = a*a*ta+b*b*tb-2*S;
		return new BigDecimal(sss);
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
	public static void tra(int[] a) {System.out.println(Arrays.toString(a));}
	public static void tra(int[][] a){for(int[] e : a){	System.out.println(Arrays.toString(e));}}
}
