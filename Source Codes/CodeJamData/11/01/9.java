import java.io.*;
import java.util.*;

public class BotTrust
{

	public static void main(String[] args)
	{
		try
		{
			// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			int T = Integer.parseInt(br.readLine());
			// PrintWriter pw = new PrintWriter(System.out);
			PrintWriter pw = new PrintWriter(new FileWriter("output"));

			for (int I = 1; I <= T; I++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine(), " \n\t", false);
				int n = Integer.parseInt(st.nextToken());
				
				int Opos = 1, Bpos = 1;
				int Oextra = 0, Bextra = 0;
				int ret = 0;
				for (int i = 0; i < n; i++)
				{
					int nextBot = (st.nextToken().equals("O") ? 0 : 1);
					int button = Integer.parseInt(st.nextToken());
					
					if (nextBot == 0)
					{
						int dist = Math.abs(Opos-button);
						if (Oextra >= dist) dist = 0;
						else dist -= Oextra;
						ret += dist+1;
						Bextra += dist+1;
						Oextra = 0;
						Opos = button;
					}
					else
					{
						int dist = Math.abs(Bpos-button);
						if (Bextra >= dist) dist = 0;
						else dist -= Bextra;
						ret += dist+1;
						Oextra += dist+1;
						Bextra = 0;
						Bpos = button;
					}
				}

				pw.println("Case #"+I+": "+ret);
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