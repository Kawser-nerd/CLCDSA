/* Andy Rock
 * April 15, 2016
 * 
 * Round 1A 2016: Problem B. 
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class B
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader("B.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B.out"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			int N = Integer.parseInt(in.readLine());
			int[] freq = new int[2501];
			for(int i=0;i<2*N-1;i++)
			{
				StringTokenizer st = new StringTokenizer(in.readLine());
				for(int j=0;j<N;j++)
					freq[Integer.parseInt(st.nextToken())]++;
			}

			out.write("Case #"+t+": ");
			for(int i=1;i<=2500;i++)
				if(freq[i] % 2 == 1)
					out.write(i+" ");
			out.write("\n");
		}

		in .close();
		out.close();
	}
}