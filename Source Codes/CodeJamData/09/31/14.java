import java.util.*;
import java.io.*;
import java.math.*;

public class p1
{
	public static void main(String[] eleusive_loves_men) throws Throwable
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		PrintWriter out=new PrintWriter(new FileOutputStream("A-small.out"));
		String[] sa=in.readLine().trim().split("\\s+");
		int N=Integer.parseInt(sa[0]);
		for(int i=1;i<=N;i++)
			out.println("Case #"+i+": "+go(in.readLine().trim()));
		out.close();
	}
	static String go(String s)
	{
		boolean[] encountered=new boolean[256];
		int[] values=new int[256];
		int[] valueOrder=new int[40];
		for(int i=0;i<40;i++)
			valueOrder[i]=i;
		valueOrder[0]=1;
		valueOrder[1]=0;
		int base=0;
		for(char c:s.toCharArray())
		{
			if(!encountered[c])
			{
				encountered[c]=true;
				values[c]=valueOrder[base];
				base++;
			}
		}
		if(base<2)
			base++;
		BigInteger answer=new BigInteger("1");
		for(int i=1;i<s.length();i++)
			answer=answer.multiply(new BigInteger(""+base)).add(new BigInteger(""+values[s.charAt(i)]));
		return answer+"";
	}
}