import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner in;
	static PrintWriter out;
	static String INPUT = "";
	
	
	static boolean q(long n)
	{
		out.println("? " + n);
		out.flush();
		return in.next().charAt(0) == 'Y';
	}
	
//	static long hans = 9;
//	
//	static boolean q(long n)
//	{
//		return 
//				hans <= n && (""+hans).compareTo("" + n) <= 0 ||
//				hans > n && (""+hans).compareTo("" + n) > 0;
//	}
	
	static void solve()
	{
		long low = 10000000000L, high = 100000000000L;
		while(high - low > 1){
			long h = high+low>>1;
			if(q(h)){
				high = h;
			}else{
				low = h;
			}
		}
		String nine = "999999999";
		if(high/10 >= 9000000000L){
			String ten = "10000000000";
			for(int i = 10;i >= 2;i--){
				if(q(Long.parseLong(ten.substring(0, i)))){
					out.println("! " + Long.toString(high).substring(0, i));
					out.flush();
					return;
				}
			}
			out.println("! " + Long.toString(high).substring(0, 1));
			out.flush();
		}else{
			for(int i = 9;i >= 1;i--){
				if(!q(Long.parseLong(nine.substring(0, i)))){
					out.println("! " + Long.toString(high).substring(0, i+1));
					out.flush();
					return;
				}
			}
			out.println("! " + Long.toString(high).substring(0, 1));
			out.flush();
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	static int ni() { return Integer.parseInt(in.next()); }
	static long nl() { return Long.parseLong(in.next()); }
	static double nd() { return Double.parseDouble(in.next()); }
	static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}