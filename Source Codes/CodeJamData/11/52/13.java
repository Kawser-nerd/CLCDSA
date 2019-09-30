package gcj2011.r3;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.Scanner;

public class BLarge {
	static String BASEPATH = "x:\\gcj\\2011r3\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + BLarge.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt1.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int n = ni();
		int[] a = new int[10002];
		for(int i = 0;i < n;i++){
			a[ni()]++;
		}
		if(n == 0){
			out.println(0);
			return;
		}
		
		int[] s = new int[n];
		int[] e = new int[n];
		int ps = 0;
		int pe = 0;
		for(int i = 0;i <= 10000;i++){
			if(a[i] < a[i+1]){
				for(int j = 0;j < a[i+1] - a[i];j++){
					s[ps++] = i;
				}
			}else if(a[i] > a[i+1]){
				for(int j = 0;j < a[i] - a[i+1];j++){
					e[pe++] = i;
				}
			}
		}
		if(ps != pe){
			throw new Error();
		}
		s = Arrays.copyOf(s, ps);
		e = Arrays.copyOf(e, pe);
		
		int low = 0;
		int high = 10001;
		while(high - low > 1){
			int mid = (high+low)/2;
			if(ok(s, e, mid)){
				low = mid;
			}else{
				high = mid;
			}
		}
		out.println(low);
	}
	
	static boolean ok(int[] s, int[] e, int x)
	{
		int n = s.length;
		BitSet used = new BitSet();
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(!used.get(j) && s[i] + x <= e[j]){
					used.set(j);
					continue outer;
				}
			}
			return false;
		}
		return true;
	}
	
	Scanner in;
	PrintWriter out;
	
	public BLarge(Scanner in, PrintWriter out)
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
			new BLarge(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
