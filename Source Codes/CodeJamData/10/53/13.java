package gcj2010.r3;

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

public class C {
	private static final SimpleDateFormat SDF = new SimpleDateFormat("_yyMMdd_HHmmss");
	
	private static final String BASEPATH = "x:\\gcj\\2010r3\\";
	private final char CHARQ = this.getClass().getSimpleName().charAt(0);
	private final String OUTPATH = BASEPATH + CHARQ;
	private final String INPATH = BASEPATH + CHARQ + "-small-attempt0.in";
//	private final String INPATH = BASEPATH + CHARQ + "-large.in";
	
//	private String INPUT = "3 -1 2 0 1 1 2";
	private String INPUT = "2 -1000 1 2000 1";
	private static final int MODE = 1; // 0:test, 1:single thread
	
	public Object solve() throws Exception
	{
		int c = ni();
		int[] p = new int[c];
		int[] v = new int[c];
		int n = 0;
		for(int i = 0;i < c;i++){
			p[i] = ni();
			v[i] = ni();
			n += v[i]; 
		}
		int[] po = new int[n];
		int pos = 0;
		for(int j = 0;j < c;j++){
			for(int k = 0;k < v[j];k++){
				po[pos++] = p[j];
			}
		}
		
		int ret = 0;
		for(;;ret++){
			int i;
			for(i = 0;i < n - 1;i++){
				if(po[i] == po[i + 1]){
					int j;
					for(j = i + 2;j < n && po[j] == po[i];j++);
					j--;
					po[i]--;
					po[j]++;
					break;
				}
			}
//			tr(Arrays.toString(po));
			if(i == n - 1)break;
		}
		
		return ret;
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
}
