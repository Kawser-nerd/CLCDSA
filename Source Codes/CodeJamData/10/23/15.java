import java.util.*;
import java.math.BigInteger;
public class C
{
	static final int MD = 100003;
	
	static HashMap<Integer, HashMap<Integer, Integer>> cv = new HashMap<Integer, HashMap<Integer, Integer>>();
	
	static int choose(int n, int k)
	{
		if(n < 0)
			return 0;
		if(n == 0 && k == 0)
			return 1;
		else if(n == 0)
			return 0;
		
		if(cv.containsKey(n) && cv.get(n).containsKey(k))
			return cv.get(n).get(k);
			
		BigInteger product = BigInteger.ONE;
			for(int i = n - k + 1; i <= n; i++)
				product = product.multiply(BigInteger.valueOf(i));
			for(int i = 2; i <= k; i++)
				product = product.divide(BigInteger.valueOf(i));
			
			product = product.mod(BigInteger.valueOf(MD));
			
			if(!cv.containsKey(n))
				cv.put(n, new HashMap<Integer, Integer>());
			cv.get(n).put(k, product.intValue());
			
			return product.intValue();
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for(int c = 1; c <= cases; c++)
		{
			int n = sc.nextInt();
			long[][] numSets = new long[n + 1][n + 1];
			for(int i = 2; i <= n; i++)
			{
				numSets[i][1] = 1;
			}
			for(int ord = 2; ord <= n; ord++)
			{
				for(int i = 2; i <= n; i++)
				{
					numSets[i][ord] = 0;
					
					for(int ordord = 1; ordord < ord; ordord++)
					{
						numSets[i][ord] += numSets[ord][ordord] * choose(i - ord - 1, ord - ordord - 1);
						numSets[i][ord] %= MD;
					}
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				ans += numSets[n][i];
				
				ans %= MD;
			}
			System.out.println("Case #" + c + ": " + ans);
		}
	}
}
