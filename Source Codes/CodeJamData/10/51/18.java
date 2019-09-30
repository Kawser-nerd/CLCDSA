import java.util.*;

public class Deranged
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		boolean[] isPrime = new boolean[1000000];
		pn = 0;
		Arrays.fill(isPrime, true);
		for(int i=2;i<isPrime.length;i++)
			if(isPrime[i])
			{
				pn++;
				if((long)i*i<isPrime.length)
					for(int j=i*i;j<isPrime.length;j+=i)
						isPrime[j] = false;
			}
		prime = new int[pn]; pn = 0;
		for(int i=2;i<isPrime.length;i++)
		{
			if(isPrime[i])
				prime[pn++] = i;
		}
		
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.println("Case #"+i+": "+solveCase());
		}
	}
	static int[] prime; static int pn;
	static final String AMB = "I don't know.";
	static String solveCase()
	{
		int D = sc.nextInt();
		int pow10 = 1;
		for(int i=0;i<D;i++)
			pow10 *= 10;
		int K = sc.nextInt();
		int[] num = new int[K];
		for(int i=0;i<K;i++)
			num[i] = sc.nextInt();
		
		if(K==1)
			return AMB;
		if(K==2)
			return num[0]==num[1] ? ""+num[0] : AMB;
		
		int max = num[0];
		for(int i=1;i<K;i++)
			if(num[i]>max)
				max = num[i];
		
		int res = -1;
		for(int i=0;i<pn;i++)
		{
			if(prime[i]<=max || prime[i]>pow10)
				continue;
			MOD = prime[i];
			int a = (int)(canon(num[2]-num[1])*inv(canon(num[1]-num[0]))%MOD);
			int b = (int)(canon(num[1]-(long)num[0]*a));
			//A.spr(prime[i]+":"+a+":"+b);
			// verify
			boolean ok = true;
			for(int j=1;j<K;j++)
				ok &= (((long)num[j-1]*a+b)%MOD) == num[j];
			if(!ok)
				continue;
			int resP =(int)(((long)num[K-1]*a+b)%MOD);
			if(res==-1)
				res = resP;
			else if(res != resP)
				return AMB;
		}
		assert res != -1;
		return ""+res;
	}
	static int MOD;
	static long canon(long num)
	{
		num %= MOD;
		if(num<0)
			num += MOD;
		return num;
	}
	static long inv(long num)
	{
		int index = MOD-2;
		long res = 1, cur = num;
		while(index!=0)
		{
			if((index&1)==1)
				res = res*cur%MOD;
			index >>= 1;
			cur = cur*cur%MOD;
		}
		return res;
	}
}
