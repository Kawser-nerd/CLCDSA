package gcj2011.r2;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.Scanner;

public class C {
	static String BASEPATH = "x:\\gcj\\2011r2\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		long n = in.nextLong();
		int u = (int)(Math.sqrt(n) + 1E-9);
		if(n == 1){
			out.println(0);
		}else{
			int[] primes = sieveEratosthenes(u);
			int ct = 1;
			for(int p : primes){
				ct--;
				for(long q = p;q <= n;q *= p, ct++);
			}
			out.println(ct);
		}
	}
	
	public static int[] sieveEratosthenes(int n) {
		int[] ret = new int[Math.max((int) (n / Math.log(n))
				+ (int) (n / (Math.log(n) * Math.log(n)) * 1.5), 2)];
		ret[0] = 2;
		int pos = 1;

		// 0:3 1:5
		// 2x+3=n
		BitSet bs = new BitSet(n / 2 + 1);
		int sup = (n - 3) / 2;
		for(int i = bs.nextClearBit(0);i <= sup;i = bs.nextClearBit(i + 1)){
			int p = 2 * i + 3;
			ret[pos++] = p;
			for(int j = i + p;j <= sup;j += p){
				bs.set(j);
			}
		}

		return Arrays.copyOf(ret, pos);
	}
	
	Scanner in;
	PrintWriter out;
	
	public C(Scanner in, PrintWriter out)
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
			new C(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
