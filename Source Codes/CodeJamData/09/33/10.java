/*
PROBLEM: Bribe the Prisoners
LANGUAGE: Java
CONTESTANT: Aram Ebtekar
*/

import java.io.*;
import java.util.*;

public class BribeThePrisoners
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		StringTokenizer st;
		
		int N = Integer.parseInt(in.readLine());
		
		for (int caseNum = 1; caseNum <= N; caseNum++)
		{
			st = new StringTokenizer(in.readLine());
			int P = Integer.parseInt(st.nextToken());
			int Q = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(in.readLine());
			int[] toRelease = new int[Q+2];
			int[][] coins = new int[Q+2][Q+2];
			
			toRelease[0] = 0;
			for (int i = 1; i <= Q; i++)
			{
				toRelease[i] = Integer.parseInt(st.nextToken());
			}
			toRelease[Q+1] = P + 1;
			
			for (int i = 0; i <= Q; i++)
			{
				coins[i][i+1] = 0;
			}
			
			for (int delta = 2; delta <= Q+1; delta++)
			{
				for (int i = 0; i <= Q+1 - delta; i++)
				{
					int min = Integer.MAX_VALUE;
					for (int k = i+1; k < i+delta; k++)
					{
						if (coins[i][k] + coins[k][i+delta] < min)
							min = coins[i][k] + coins[k][i+delta];
					}
					coins[i][i+delta] = min + toRelease[i+delta] - toRelease[i] - 2;
				}
			}

			out.println("Case #" + caseNum + ": " + coins[0][Q+1]);
		}
		
		in.close();
		out.close();
		System.exit(0);
	}
}
