import java.util.*;
import java.io.*;
public class R1A {
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("A-large.in"));
		PrintStream out = new PrintStream(new File("A-large.out"));
		int cas = in.nextInt();
		
		for(int iii = 0; iii < cas; iii++)
		{
			TreeSet<String> s = new TreeSet<String>();
			s.add("");
			
			int N = in.nextInt();
			int M = in.nextInt();
			for(int i = 0; i < N; i++)
			{
				String str = in.next();
				s.add(str);
			}
			int count = 0;
			for(int i = 0; i < M; i++)
			{
				String str = in.next();
				
				int curr = 0;
				
				while(true)
				{
					int ind = str.indexOf('/', curr+1);
					if(ind < 0)
						{
							if(!s.contains(str))
							{
								count++;
								s.add(str);
							}
							break;
						}
					
					if(!s.contains(str.substring(0, ind)))
					{
						count++;
						s.add(str.substring(0,ind));
					}
					curr = ind;
				}
			}
			out.println("Case #" + (iii+1) + ": " + count);	
		}
		
		out.close();
	}
}