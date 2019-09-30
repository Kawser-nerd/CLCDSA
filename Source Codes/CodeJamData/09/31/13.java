package googlejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class AllYourBase {

	public static void main(String[] args) throws Exception
	{
		BufferedReader in=new BufferedReader(new FileReader("C:\\A-large.in.txt"));
		PrintWriter pr=new PrintWriter(new FileWriter("C:\\Alargeout.txt"));
		
		int T=Integer.parseInt(in.readLine().trim());
		
		for(int i=0;i<T;i++)
		{
			String temp=in.readLine().trim();
			
			long no=cal(temp);
			pr.println("Case #"+(i+1)+": "+no);
		}
		
		pr.close();
	}
	
	public static long cal(String temp)
	{
		Map<String,Integer> m=new HashMap<String,Integer>();
		int max=0;
		
		List<Integer> s=new ArrayList<Integer>();
		s.add(1);
		m.put(temp.charAt(0)+"", 1);
		
		for(int i=1;i<temp.length();i++)
		{
			if(m.containsKey(temp.charAt(i)+""))
				s.add(m.get(temp.charAt(i)+""));
			else
			{
				m.put(temp.charAt(i)+"", max);
				s.add(m.get(temp.charAt(i)+""));
				max++;
			}
			
			if(max==1)
				max++;
		}
		int base=max;
		if(base<2)
			base=2;
		
		long result=0;
		for(int i=0;i<s.size();i++)
		{
			System.out.print(s.get(i));
			result=result*base+s.get(i);
		}
		System.out.println();
		return result;
	}
}
