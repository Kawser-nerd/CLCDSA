import java.io.*;
import java.util.*;

public class C
{
	public static void main (String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("C-large.out"));
		
		int num = Integer.parseInt(br.readLine());
		for (int z = 1; z <= num; z++)
		{
			System.out.println(z);
			int len = Integer.parseInt(br.readLine());
			String[] sp = br.readLine().split(" ");
			int numOut = Integer.parseInt(sp[0]);
			int[] toOut = new int [numOut];
			for (int i = 0; i < numOut; i++)
				toOut[i] = Integer.parseInt(sp[i+1]);
			
			int[] x = new int [len];
			Arrays.fill(x, -1);
			int[] un10 = new int [(int)Math.ceil(len/10)+1];
			int[] un100 = new int [(int)Math.ceil(len/100)+1];
			int[] un1000 = new int [(int)Math.ceil(len/1000)+1];
			int[] un10000 = new int [(int)Math.ceil(len/10000)+1];
			
			int c = -1;
			for (int i = 0; i < len; i++)
			{
				int t = i % (len-i);
				while (t >= 0)
				{
					if (c % 10000 == 9999 && len-c > 10000 && t > 10000-un10000[c/10000+1])
					{
						t -= 10000-un10000[c/10000+1];
						c = (c+10000)%len;
					}
					else if (c % 1000 == 999 && len-c > 1000 && t > 1000-un1000[c/1000+1])
					{
						t -= 1000-un1000[c/1000+1];
						c = (c+1000)%len;
					}
					else if (c % 100 == 99 && len-c > 100 && t > 100-un100[c/100+1])
					{
						t -= 100-un100[c/100+1];
						c = (c+100)%len;
					}
					else if (c % 10 == 9 && len-c > 10 && t > 10-un10[c/10+1])
					{
						t -= 10-un10[c/10+1];
						c = (c+10)%len;
					}
					else
					{
						c = (c+1)%len;
						if (x[c] == -1)
							t--;
					}
				}
				x[c] = i;
				un10[c/10]++;
				un100[c/100]++;
				un1000[c/1000]++;
				un10000[c/10000]++;
			}
			
			String out = "Case #" + z + ":";
			for (int i = 0; i < numOut; i++)
				out += " " + (x[toOut[i]-1]+1);
			
			ps.println(out);
		}
		
		br.close();
		ps.close();
	}
}