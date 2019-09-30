import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class CMain {
	public static String F(int N)
	{
		BigDecimal r = new BigDecimal("1");
		BigDecimal a = new BigDecimal("3");
		a = a.add(new BigDecimal("2.2360679774997896964091736687313"));
		int i;
		for (i = 0; i < N; ++i)
			r = r.multiply(a);
		BigInteger b = r.toBigInteger().mod(new BigInteger("1000"));
		return b.toString();
	}
	public static void main(String[] args)
	{
	      Scanner in = new Scanner(System.in);
	      PrintWriter out = new PrintWriter(System.out);
	      File outf = new File("C-small.out");
	      File inf = new File("C-small.in");
	      try
	      {
	    	  in = new Scanner(inf);
	    	  out = new PrintWriter(outf);
	      }catch(Exception ex){}

	      int T = in.nextInt();
	      int t;
	      for (t = 1; t <= T; ++t)
	      {
	    	  int N = in.nextInt();
	    	  String rs = F(N);
	    	  while (rs.length() < 3)
	    		  rs = "0" + rs;
	    	  out.println("Case #" + String.valueOf(t) + ": " + rs);
	      }

	      out.flush();		
	}
}
