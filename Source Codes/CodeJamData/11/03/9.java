import java.io.*;
import java.util.*;

public class CandySplit
{
	
	public static void main(String[] args)
	{
		try
		{
			// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader br = new BufferedReader(new FileReader("C-large (1).in"));
			int T = Integer.parseInt(br.readLine());
			// PrintWriter pw = new PrintWriter(System.out);
			PrintWriter pw = new PrintWriter(new FileWriter("output"));
			
			for (int I = 1; I <= T; I++)
			{
				int N = Integer.parseInt(br.readLine());
				
				int small = Integer.MAX_VALUE, tot = 0, xor = 0;
				StringTokenizer st = new StringTokenizer(br.readLine(), " ", false);
				
				for (int i = 0; i < N; i++)
				{
					int k = Integer.parseInt(st.nextToken());
					if (k < small) small = k;
					tot += k;
					xor = xor ^ k;
				}
				
				if (xor != 0) pw.println("Case #"+I+": NO");
				else pw.println("Case #"+I+": "+(tot-small));
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