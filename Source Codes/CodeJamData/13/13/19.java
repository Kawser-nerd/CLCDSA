import java.io.*;
import java.util.Scanner;
public class c {
public static void main(String[] args) throws IOException
{
	Scanner input = new Scanner(System.in);
	PrintWriter out = new PrintWriter(new File("c.txt"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.print("Case #" + (t+1) + ": \n");
		int r = input.nextInt(), n = input.nextInt(), m = input.nextInt(), k = input.nextInt();
		for(int rr = 0; rr<r; rr++)
		{
			int twopow = 0, threepow = 0, fivepow = 0;
			for(int i = 0; i<k; i++)
			{
				int p = input.nextInt();
				int fives = 0;
				while(p%5 == 0 && p > 0)
				{
					p/=5;
					fives++;
				}
				fivepow = Math.max(fives, fivepow);
				int twos = 0;
				while(p%2 == 0 && p > 0)
				{
					p/=2;
					twos++;
				}
				twopow = Math.max(twos, twopow);
				int threes = 0;
				while(p%3 == 0 && p > 0)
				{
					p/=3;
					threes++;
				}
				threepow = Math.max(threes, threepow);
			}
			int used = 0;
			while(fivepow>0)
			{
				used++;
				fivepow--;
				out.print(5);
			}
			while(threepow>0)
			{
				used++;
				threepow--;
				out.print(3);
			}
			while(twopow > n-used)
			{
				twopow -= 2;
				used++;
				out.print(4);
			}
			while(used<n)
			{
				used++;
				out.print(2);
			}
			out.println();
		}
	}
	out.close();
}
}
