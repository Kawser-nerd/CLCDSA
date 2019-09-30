package googlejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class CrazyRows {
	public static void main(String[] args) throws Exception
	{
		BufferedReader in=new BufferedReader(new FileReader("c:\\A-large.in.txt"));
		PrintWriter pr=new PrintWriter(new FileWriter("C:\\A-large.out.txt"));
		
        int T=Integer.parseInt(in.readLine().trim());
		
        
		for(int i=0;i<T;i++)
		{
			int N=Integer.parseInt(in.readLine().trim());
		    String[] m=new String[N];
		    int []l=new int[N];
		    for(int j=0;j<N;j++)
		        m[j]=in.readLine().trim();
			for(int j=0;j<N;j++)
			{
				int k;
				for(k=m[j].length()-1;k>=0;k--)
				{
					if(m[j].charAt(k)=='1')
						break;
				}
				l[j]=k;
			}
	        pr.println("Case #"+(i+1)+": "+getResult(0,l));
		
		}
		pr.close();
	}
	
	public static int getResult(int now,int[] l)
	{
		if(now==l.length)
			return 0;
		int i;
		for(i=now;i<l.length;i++)
			if(l[i]<=now)
				break;
	    int tr=i-now;
	    for(int j=i;j-1>=now;j--)
	    {
	    	int temp=l[j];
	    	l[j]=l[j-1];
	    	l[j-1]=temp;
	    }
	    return tr+getResult(now+1,l);
	}
}
