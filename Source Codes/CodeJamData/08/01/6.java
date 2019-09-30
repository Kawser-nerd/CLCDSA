import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter pr = new PrintWriter("A-large.out");
		int cas = Integer.parseInt(br.readLine().trim());
		for(int iii = 0; iii < cas; iii++)
		{
			int S = Integer.parseInt(br.readLine().trim());
			String names[] = new String[S];
			//Case sensitive?
			for(int i = 0;i < S; i++)
				names[i] = br.readLine().trim();
			
			Arrays.sort(names);
			
			int Q = Integer.parseInt(br.readLine().trim());
			
			boolean seen[] = new boolean[S];
			Arrays.fill(seen, false);
			int numSeen = 0;
			int answer = 0;
			for(int i = 0; i < Q; i++)
			{
				String query = br.readLine().trim();
				
				int ind = Arrays.binarySearch(names, query);
				if(ind >= 0)
				{					
					if(!seen[ind])
					{
						seen[ind] = true;
						numSeen++;
						if(numSeen >= S)
						{
							answer++;
							Arrays.fill(seen, false);
							seen[ind] = true;
							numSeen = 1;
						}
					}
				}
			}
			
			pr.println("Case #" + (iii+1) + ": " + answer);
		}
		pr.close();
	}
}
