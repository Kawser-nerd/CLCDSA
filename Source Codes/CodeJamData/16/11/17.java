/* Andy Rock
 * April 15, 2016
 * 
 * Round 1A 2016: Problem A. 
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class A
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader("A.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			char[] S = in.readLine().toCharArray();

			String ans = ""+S[0];
			char left = S[0], right = S[0];
			for(int i=1;i<S.length;i++)
				if(S[i] >= left)
				{
					left = S[i];
					ans = S[i]+ans;
				}
				else
				{
					right = S[i];
					ans = ans+S[i];
				}

			out.write("Case #"+t+": ");
			out.write(ans);
			out.write("\n");
		}

		in .close();
		out.close();
	}
}