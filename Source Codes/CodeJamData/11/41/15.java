package gcj2011.r2;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class A {
	static String BASEPATH = "x:\\gcj\\2011r2\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int x = ni();
		int s = ni();
		int r = ni();
		int t = ni();
		int n = ni();
		int[] w = new int[n];
		int[] plus = new int[n];
		int left = x;
		for(int i = 0;i < n;i++){
			w[i] = -ni()+ni();
			plus[i] = ni();
			left -= w[i];
		}
		int[] len = new int[101];
		for(int i = 0;i < n;i++){
			len[plus[i]] += w[i];
		}
		len[0] = left;
		
		double lt = t;
		double gt = 0;
		for(int i = 0;i < 101;i++){
			double use = Math.min(lt, (double)len[i] / (r+i));
			if(use < lt){
				gt += use;
			}else{
				gt += use + (len[i]-use*(r+i)) / (s+i);
			}
			lt -= use;
		}
		out.printf("%1.8f\n", gt);
	}
	
	Scanner in;
	PrintWriter out;
	
	public A(Scanner in, PrintWriter out)
	{
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		
		Scanner in = INPUT.isEmpty() ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = INPUT.isEmpty() ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new A(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
