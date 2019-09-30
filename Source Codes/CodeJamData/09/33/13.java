import java.util.*;
import java.io.*;

public class p3
{
	//nguys[i]=number of unreleasable guys between the (i) and (i+1) prisoners.
	//Prisoners are 1-indexed, so nguys[0] is the number of the guys to the left of guy 1.
	//And nguys[Q] is the number of guys to the right of guy Q.
	static int[] nguys;
	static int[] releasedguys;
	static int[][] dp;
	static int P,Q;
	public static void main(String[] eleusive_loves_men) throws Throwable
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in")));
		PrintWriter out=new PrintWriter(new FileOutputStream("C-small.out"));
		String[] sa=in.readLine().trim().split("\\s+");
		int KK=Integer.parseInt(sa[0]);
		for(int qq=1;qq<=KK;qq++)
		{
			sa=in.readLine().trim().split("\\s+");
			P=Integer.parseInt(sa[0]);
			Q=Integer.parseInt(sa[1]);
			nguys=new int[Q+1];
			releasedguys=new int[Q];
			dp=new int[Q+1][Q+1];
			for(int i=0;i<Q+1;i++)
				for(int j=0;j<Q+1;j++)
					dp[i][j]=-1;
			sa=in.readLine().trim().split("\\s+");
			for(int i=0;i<Q;i++)
				releasedguys[i]=Integer.parseInt(sa[i]);
			nguys[0]=releasedguys[0]-1;
			for(int i=1;i<Q;i++)
				nguys[i]=releasedguys[i]-releasedguys[i-1]-1;
			nguys[Q]=P-releasedguys[Q-1];
			int ret=solve(0,Q);
			out.println("Case #"+(qq)+": "+ret);
		}
		out.close();
	}
	static int solve(int a,int b)
	{
		if(dp[a][b]!=-1)
			return dp[a][b];
		if(a==b)
			return dp[a][b]=0;
		if(a==b-1)
			return dp[a][b]=nguys[a]+nguys[b];
		int guystopayoff=-2;
		for(int i=a;i<=b;i++)
			guystopayoff+=nguys[i]+1;
		int best=999999999;
		for(int c=a;c<b;c++)
		{
			int candidate=solve(a,c)+solve(c+1,b);
			if(candidate<best)
				best=candidate;
		}
		return dp[a][b]=best+guystopayoff;
	}
}