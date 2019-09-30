import java.io.*;
import java.util.*;

public class Goro
{
	
	public static void main(String[] args)
	{
		try
		{
			// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
			int T = Integer.parseInt(br.readLine());
			// PrintWriter pw = new PrintWriter(System.out);
			PrintWriter pw = new PrintWriter(new FileWriter("output"));
			
			for (int I = 1; I <= T; I++)
			{
				int N = Integer.parseInt(br.readLine());
				// int[] perm = new int[N];
				StringTokenizer st = new StringTokenizer(br.readLine(), " ", false);
				
				int ret = N;
				for (int i = 0; i < N; i++)
				{
					int k = Integer.parseInt(st.nextToken());
					if (k == i+1) ret--;
				}
				
				pw.println("Case #"+I+": "+ret+".000000");
			}
			
			br.close();
			pw.flush(); pw.close();
		}
		catch (IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
}