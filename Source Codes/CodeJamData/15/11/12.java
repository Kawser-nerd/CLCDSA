import java.util.*;
import java.io.*;
public class A
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("A-large.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			long[] array = new long[n];
			long rate = 0;
			for(int y = 0; y < n; y++)
			{
				array[y] = in.nextInt();
				
				if(y > 0)
				{
					rate = Math.max(rate, array[y - 1] - array[y]);
				}
			}
			
			long result1 = 0;
			long result2 = 0;
			for(int z = 0; z < array.length - 1; z++)
			{
				result1 += Math.max(0, array[z] - array[z + 1]);
				result2 += Math.min(rate, array[z]);
			}
			
			out.println("Case #" + (x + 1) + ": " + result1 + " " + result2);
		}
		
		out.close();
	}
}
