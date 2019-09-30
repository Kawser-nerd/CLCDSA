import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.System.out;

public class CC {
	static BufferedReader _in = new BufferedReader(new InputStreamReader(System.in));
	static String _string;
	static StringTokenizer _stok;
	static String nextLine() throws IOException {
		_string = _in.readLine();
		_stok = new StringTokenizer(_string);
		return _string;}
	static String nxt() {return _stok.nextToken();}
	static String nxw() {while (!_stok.hasMoreTokens())
		try {nextLine();} catch (IOException e) {e.printStackTrace();}
		return _stok.nextToken();}
	static int nxi()		{return Integer.parseInt(nxw());} // 2.1 x 10^9, 
	static long nxl()		{return Long.parseLong(nxw());}   // 9.2 x 10^18, 
	static float nxf()	{return Float.parseFloat(nxw());}
	static double nxd() 	{return Double.parseDouble(nxw());}
	static BigInteger nxb()	{return new BigInteger(nxw());}
	static void Dprint(Object s)   {if (debug) System.out.print(s);}
	static void Dprintln(Object s) {if (debug) System.out.println(s);}
	static void Dprintln()         {if (debug) System.out.println();}
	static void Dprintf(String s, Object... args) {if (debug) System.out.printf(s, args);}
	
	static boolean debug = false;

	public static void main(String[] args) throws Exception {
		nextLine();
		int Cases = nxi();
		for (int Case=0; Case<Cases; Case++) {

			nextLine();
			int N = nxi();
			long L = nxl();
			long H = nxl();
			long[] freqs = new long[N]; 
			nextLine();
			for (int i=0; i<N; i++) {
				freqs[i] = nxl();
			}
/*			long gcf = freqs[0];
			for (int i=1; i<N; i++) {
				gcf = gcd(gcf, freqs[i]);
			}
			if (L <= gcf && gcf <= H) {
				System.out.println("Case #" + (Case+1) + ": " + gcf);
				continue;
			}
			long lcm = freqs[0];
			boolean ok = true;
			for (int i=1; i<N && ok; i++) {
				lcm = lcm * freqs[i] / gcd(freqs[i], lcm);
				if (lcm > H) {
					ok = false;
				}
			}
			if (ok) {
				System.out.println("Case #" + (Case+1) + ": " + lcm);
				continue;
			}
*/
			boolean Ok = true;
			long p = L;
			for (p=L; p<=H; p++) {
				Ok = true;
				for (int i=0; i<N; i++) {
					long fi = freqs[i];
					if (p < fi && fi % p != 0) {
						Ok =false; break; 
					}
					if (p > fi && p%fi != 0) {
						Ok =false; break; 
					}
				}
				if (Ok) break;
			}
			System.out.println("Case #" + (Case+1) + ": " + (Ok? p : "NO"));
		} // end for each case

	} // end main
	
	static long gcd(long a, long b) {
		//if (a < b) return gcd(b,a);
	    if (b == 0)
	       return a;
	    else
	       return gcd(b, a % b);
	}
}


//class Node {
//	int x, y;
//	Node left, right, parent;
//}
