import java.util.*;
import java.math.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int caseN=cin.nextInt();
		for (int caseI=1;caseI<=caseN;caseI++)
		{
			int n=cin.nextInt();
			BigInteger[] times=new BigInteger[n];
			for (int i=0;i<n;i++)
				times[i]=new BigInteger(cin.next());
			BigInteger ans=times[0].subtract(times[1]).abs();
			for (int i=2;i<n;i++)
				ans=ans.gcd(times[i].subtract(times[i-1]).abs());
			ans=ans.subtract(times[0].mod(ans)).mod(ans);
			System.out.printf("Case #%d: %s",caseI,ans.toString());
			System.out.println();
		}
	}
}

