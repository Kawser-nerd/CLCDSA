import java.util.*;
import java.io.*;
public class D
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("D-large.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			double[] naomi = new double[n];
			for(int y = 0; y < n; y++)
			{
				naomi[y] = in.nextDouble();
			}
			
			double[] ken = new double[n];
			for(int z = 0; z < n; z++)
			{
				ken[z] = in.nextDouble();
			}
			
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			int index = 0;
			int win1 = 0;
			for(int a = 0; a < ken.length; a++)
			{
				while(index < n && naomi[index] < ken[a])
				{
					index++;
				}
				
				if(index < n)
				{
					win1++;
					index++;
				}
			}
			
			index = 0;
			int win2 = 0;
			for(int b = 0; b < naomi.length; b++)
			{
				while(index < n && ken[index] < naomi[b])
				{
					index++;
					win2++;
				}
				
				index++;
			}
			
			out.println("Case #" + (x + 1) + ": " + win1 + " " + win2);
		}
		
		out.close();
	}
}
