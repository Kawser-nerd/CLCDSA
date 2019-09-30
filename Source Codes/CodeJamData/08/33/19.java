import java.io.*;
import java.util.*;
import java.math.*;

public class Problem3 {
	public static void main(String[] args) throws IOException{
		   Scanner in=new Scanner(new FileReader("Problem3.in"));
		   PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Problem3.out")));
		   int c=in.nextInt();
		   for (int cn=0;cn<c;cn++)
		   {
			   int n=in.nextInt();
			   int m=in.nextInt();
			   long x=in.nextInt();
			   long y=in.nextInt();
			   long z=in.nextInt();
			   long sub[]=new long[n];
			   BigInteger ans[]=new BigInteger[n];
			   long array[]=new long[m];
			   for (int i=0;i<m;i++)
				   array[i]=in.nextInt();
			   for (int i=0;i<n;i++)
			   {
				   sub[i]=array[i%m];
				   array[i%m]=(x*array[i%m]+y*(i+1))%z;
			   }
			   Arrays.fill(ans, BigInteger.ONE);
			   for (int i=1;i<n;i++)
				   for (int j=0;j<i;j++)
				   {
					   if (sub[j]<sub[i])
						   ans[i]=ans[i].add(ans[j]);
				   }
			   BigInteger sum=BigInteger.ZERO;
			   for (int i=0;i<n;i++)
				   sum=sum.add(ans[i]);
			   sum=sum.remainder(new BigInteger("1000000007"));
			   out.write("Case #"+(cn+1)+": "+sum.toString()+"\n");
		   }
		   in.close();
		   out.close();
	}
}
