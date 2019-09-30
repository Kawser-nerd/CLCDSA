import java.io.*;
import java.util.*;
import java.math.*;
class C
{
	public static void main(String[] arg)throws IOException
	{
		BigDecimal base=new BigDecimal("5.2360679774997896964091736687312762354406183596115257242708972454105209256378048994144144083787822749");
		int t,n;
		Scanner scan=new Scanner(System.in);
		t=scan.nextInt();
		for(int ca=1;ca<=t;ca++)
		{
			n=scan.nextInt();
			BigDecimal ans=base.pow(n);
			String ss=ans.toPlainString();
			//System.out.println(ss);
			int i;
			for(i=0;ss.charAt(i)!='.';i++);
			String out="";
			for(int j=1;j<=3;j++)
			{
				if(i-j>=0)out=ss.substring(i-j,i-j+1)+out;
				else out="0"+out;
			}
			System.out.println("Case #"+ca+": "+out);
		}
	}
}
