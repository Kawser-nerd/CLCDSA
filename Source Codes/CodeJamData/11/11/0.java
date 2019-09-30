import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Bai1 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Alarge.out"));
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			
			long n = sc.nextLong();
			int pd = sc.nextInt();
			int pg = sc.nextInt();
			boolean possible = true;
			
			if(pg == 0 && pd != 0) possible = false;
			if(pg == 100 && pd != 100) possible = false;
			
			int d = BigInteger.valueOf(pd).gcd(BigInteger.valueOf(100)).intValue();
			
			d = 100 / d;
			
			if(d > n) possible = false;

			pw.print("Case #" + test + ": ");
			if(possible) pw.print("Possible");
			else pw.print("Broken");
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
