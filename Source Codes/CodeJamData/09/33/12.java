package googlejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class BribethePrisoner2 {
    static int min;	
    
    static Map<String,Integer> m;
	public static void main(String[] args) throws Exception
	{
		BufferedReader in=new BufferedReader(new FileReader("c:\\C-large.in.txt"));
		PrintWriter pr=new PrintWriter(new FileWriter("C:\\Clargeout.txt"));
		
	    int T=Integer.parseInt(in.readLine().trim());
		
		for(int i=0;i<T;i++)
		{
			String[] temp=in.readLine().trim().split("[ ]+");
			int p=Integer.parseInt(temp[0]);
			int q=Integer.parseInt(temp[1]);
			int[] br=new int[q+2];
			br[0]=-1;
			br[q+1]=p;
			String[] temp1=in.readLine().trim().split("[ ]+");
			for(int j=0;j<q;j++)
			{
				br[j+1]=Integer.parseInt(temp1[j])-1;
			}
			
			m=new HashMap<String,Integer>();
			
			System.out.println(i);
			//System.out.println("-------------");
			pr.println("Case #"+(i+1)+": "+search(0,br.length-1,br));
		}
		
		pr.close();
	}
	
	static int search(int l,int r,int[] br)
	{
		if(m.containsKey(l+" "+r))
			return m.get(l+" "+r);
		
		if(l+1==r)
			return 0;
		
		int result=-1;
		for(int i=l+1;i<r;i++)
		{
			int t=search(l,i,br)+search(i,r,br)+br[r]-br[l]-2;
			if(result==-1||result>t)
				result=t;
		}
		if(result==-1)
			System.out.println("!!!!");
		
		m.put(l+" "+r, result);
		return result;
	}
}
