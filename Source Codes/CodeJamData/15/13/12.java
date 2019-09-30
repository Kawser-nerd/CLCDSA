import java.util.*;
import java.io.*;
public class C
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("C-large.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			int[] xs = new int[n];
			int[] ys = new int[n];
			for(int y = 0; y < n; y++)
			{
				xs[y] = in.nextInt();
				ys[y] = in.nextInt();
			}
			
			out.println("Case #" + (x + 1) + ":");
			for(int z = 0; z < xs.length; z++)
			{
				ArrayList<Double> angles = new ArrayList<Double>();
				for(int a = 0; a < xs.length; a++)
				{
					if(a != z)
					{
						double current = Math.atan2(ys[a] - ys[z], xs[a] - xs[z]);
						angles.add(current);
						angles.add(current + 2.0 * Math.PI);
					}
				}
				
				Collections.sort(angles);
				int index = 0;
				int result = n;
				for(int b = 0; b < n; b++)
				{
					while(index < angles.size() && angles.get(index) < angles.get(b) + Math.PI + 1E-12)
					{
						index++;
					}
					
					result = Math.min(result, n - (index - b) - 1);
				}
				
				if(n == 1)
				{
					out.println(0);
				}
				else
				{
					out.println(result);
				}
			}
		}
		
		out.close();
	}
}
