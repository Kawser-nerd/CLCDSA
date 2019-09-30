import java.io.*;
import java.util.*;

import java.util.*;

public class A
{
	public static void main (String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("A-large.out"));
		
		int num = Integer.parseInt(br.readLine());
		for (int z = 1; z <= num; z++)
		{
			String[] sp = br.readLine().split(" ");
			int trees = Integer.parseInt(sp[0]);
			int A = Integer.parseInt(sp[1]);
			int B = Integer.parseInt(sp[2]);
			int C = Integer.parseInt(sp[3]);
			int D = Integer.parseInt(sp[4]);
			long X = Long.parseLong(sp[5]);
			long Y = Long.parseLong(sp[6]);
			int M = Integer.parseInt(sp[7]);
			
			int[][] mod3 = new int [3][3];
			
			for (int i = 0; i < trees; i++)
			{
				mod3[(int)(X%3)][(int)(Y%3)]++;
				X = (A*X+B) % M;
				Y = (C*Y+D) % M;
			}
			
			long out = 0;
			for (int i = 0; i < 9; i++)
				for (int j = i; j < 9; j++)
					for (int k = j; k < 9; k++)
					{
						int a = i/3, b = i%3, c = j/3, d = j%3, e = k/3, f = k%3;
						if ((a+c+e)%3 != 0)
							continue;
						if ((b+d+f)%3 != 0)
							continue;
						
						long t = (long)mod3[a][b];
						if (i == j)
						{
							t *= mod3[c][d]-1;
							t /= 2;
							if (j == k)
							{
								t *= mod3[e][f]-2;
								t /= 3;
							}
						}
						else
						{
							t *= mod3[c][d];
							if (j == k)
							{
								t *= mod3[e][f]-1;
								t /= 2;
							}
							else
								t *= mod3[e][f];
						}
						out += t;
					}				
						
			ps.println("Case #" + z + ": " + out);
		}
		
		br.close();
		ps.close();
	}
}