import java.util.*;
import java.io.*;
public class A
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("A-small.out")));
		
		int t = in.nextInt();
		
		for(int x = 0; x < t; x++)
		{
			int row1 = in.nextInt() - 1;
			
			HashSet<Integer> cards = new HashSet<Integer>();
			for(int y = 0; y < 4; y++)
			{
				for(int z = 0; z < 4; z++)
				{
					int card = in.nextInt();
					
					if(y == row1)
					{
						cards.add(card);
					}
				}
			}
			
			int row2 = in.nextInt() - 1;
			
			int chosen = -1;
			int count = 0;
			for(int a = 0; a < 4; a++)
			{
				for(int b = 0; b < 4; b++)
				{
					int card = in.nextInt();
					
					if(a == row2 && cards.contains(card))
					{
						chosen = card;
						count++;
					}
				}
			}
			
			out.print("Case #" + (x + 1) + ": ");
			if(count == 1)
			{
				out.println(chosen);
			}
			else if(count == 0)
			{
				out.println("Volunteer cheated!");
			}
			else
			{
				out.println("Bad magician!");
			}
		}
		
		out.close();
	}
}
