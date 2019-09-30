package gcj2011.r3;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class D {
	static String BASEPATH = "x:\\gcj\\2011r3\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		char[] S = in.next().toCharArray();
		rec(S, 0, 0);
	}
	
	void rec(char[] S, int pos, long cur)
	{
		if(S.length == pos){
			long sq = (long)Math.sqrt(cur);
			for(long i = sq-1;i <= sq+10;i++){
				if(i*i==cur){
					StringBuilder sb = new StringBuilder();
					for(int j = 0;j < S.length;j++){
						if(cur<<63-j<0){
							sb.append('1');
						}else{
							sb.append('0');
						}
					}
					out.println(sb.reverse());
				}
			}
			return;
		}
		
		if(S[pos] == '?'){
			rec(S, pos+1, cur*2);
			rec(S, pos+1, cur*2+1);
		}else{
			rec(S, pos+1, cur*2+(S[pos]-'0'));
		}
	}
	
	Scanner in;
	PrintWriter out;
	
	public D(Scanner in, PrintWriter out)
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
			new D(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
