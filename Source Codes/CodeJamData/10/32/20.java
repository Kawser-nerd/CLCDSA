import java.io.*;
import java.util.*;

public class LoadTest
{
	
	public static void main(String[] args)
	{
		try
		{
			BufferedReader BR = new BufferedReader(new FileReader("B-large.in"));
			PrintWriter PW = new PrintWriter(new FileWriter("B-large.out"));
			
			int T = Integer.parseInt(BR.readLine());
			
			for (int I = 0; I < T; I++)
			{
				StringTokenizer ST = new StringTokenizer(BR.readLine());
				long L = Long.parseLong(ST.nextToken());
				long P = Long.parseLong(ST.nextToken());
				long C = Long.parseLong(ST.nextToken());
				
				// Just search over powers!
				long div = P/L;
				if (P%L > 0) div++;
				
				int binary = 0;
				long F = C;
				while (F < div)
				{
					F = F*F;
					binary++;
				}
				PW.println("Case #"+(I+1)+": "+binary);
			}
			
			PW.flush(); PW.close(); BR.close();
		}
		catch (IOException ie)
		{
			
		}
	}
	
}