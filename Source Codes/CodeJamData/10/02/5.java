import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {


	public static void main(String args[]) throws Exception {
		//String inFile = args[0];
		//String inFile = "B-example.in";
		//String inFile = "B-small-attempt0.in";
		String inFile = "B-large.in";
		String outFile = inFile + ".out";
		LineNumberReader lin = new LineNumberReader(new InputStreamReader(new FileInputStream(inFile)));
		PrintWriter out = new PrintWriter(new File(outFile));
		int NCASE = Integer.parseInt(lin.readLine());
		for(int CASE = 1; CASE <= NCASE; CASE++) {
			out.print("Case #" + CASE + ": ");
			String l = lin.readLine();
			String ll[] = l.split(" ");
			int N = Integer.parseInt(ll[0]);
			BigInteger t[] = new BigInteger[N];
			for(int i = 0; i < N; i++)
				t[i] = new BigInteger(ll[i + 1]);
			BigInteger T = null;
			for(int a = 0; a < N; a++)
				for(int b = a; ++b < N; ) {
					BigInteger d = t[a].subtract(t[b]).abs();
					if(T == null)
						T = d;
					else
						T = T.gcd(d);
				}
			BigInteger y = t[0].mod(T);
			if(!y.equals(BigInteger.ZERO))
				y = T.subtract(y);
			out.println(
				y
			);
		}
		lin.close();
		out.close();
	}
}