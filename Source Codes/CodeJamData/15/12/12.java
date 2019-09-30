import java.util.*;
import java.io.*;
public class B
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("B-large.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int b = in.nextInt();
			long n = in.nextInt();
			
			long[] barbers = new long[b];
			for(int y = 0; y < b; y++)
			{
				barbers[y] = in.nextInt();
			}
			
			long low = 0;
			long high = (long)1E17;
			while(low < high)
			{
				long mid = (low + high) / 2;
				
				long count = 0;
				for(int z = 0; z < barbers.length; z++)
				{
					count += mid / barbers[z] + 1;
				}
				
				if(count < n)
				{
					low = mid + 1;
				}
				else
				{
					high = mid;
				}
			}
			
			int count = 0;
			for(int a = 0; a < barbers.length; a++)
			{
				count += (low + barbers[a] - 1) / barbers[a];
			}
			
			int result = 0;
			for(int c = 0; c < barbers.length; c++)
			{
				if(low % barbers[c] == 0)
				{
					if(count == n - 1)
					{
						result = c;
						break;
					}
					
					count++;
				}
			}
			
			out.println("Case #" + (x + 1) + ": " + (result + 1));
		}
		
		out.close();
	}
}
