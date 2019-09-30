import java.io.*;
import java.math.*;
import java.util.*;

public class PartElf
{
	static long gcd(long a, long b) { return b==0 ? a : gcd(b, a%b); }
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		for(int caseId=1,totalCases=sc.nextInt();caseId<=totalCases;caseId++)
		{
			System.out.println("Case #"+caseId+": "+solve());
			
			//Add logic here
			
			System.out.flush();
		}
	}
	
	static String solve() {
		String[] fraction = sc.next().split("/");
		long p = Long.parseLong(fraction[0]);
		long q = Long.parseLong(fraction[1]);
		long g = gcd(p, q);
		p /= g;
		q /= g;
		
		int powQ = 0;
		while(q>1) {
			if(q%2 != 0)
				return "impossible";
			q /= 2;
			powQ++;
		}
		
		int powP = 0;
		while(p>1) {
			powP++;
			p /= 2;
		}
		
		return "" + (powQ - powP);
	}
}
