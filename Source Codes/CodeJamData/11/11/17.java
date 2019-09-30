package jam2011;
import java.io.*;
import java.util.*;

// Marian G Olteanu
// round 1A
public class AA
{
	public static void main(String[] args)
	throws Exception
	{
		BufferedReader inputFile = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
		int cases = Integer.parseInt(inputFile.readLine());
		
		PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
		for (int i = 1; i <= cases; i++)
		{
			String lineT[] = tokenize(inputFile.readLine());
			long n = Long.parseLong(lineT[0]);
			long pd = Long.parseLong(lineT[1]);
			long pg = Long.parseLong(lineT[2]);
			
			String out = null;
			if (pg == 0)
				out = pd == 0 ? "Possible" : "Broken";
			else if (pg == 100)
				out = pd == 100 ? "Possible" : "Broken";
			else
			{
				if (n >= 100)
					out = "Possible";
				else
				{
					int nnn = 100;
					while (pd % 2 == 0 && nnn % 2 == 0 || pd % 5 == 0 && nnn % 5 == 0)
					{
						if (pd % 2 == 0 && nnn % 2 == 0)
						{
							nnn /= 2;
							pd /= 2;
						}
						if (pd % 5 == 0 && nnn % 5 == 0)
						{
							nnn /= 5;
							pd /= 5;
						}
					}
					//System.err.println(nnn);
					out = nnn <= n ? "Possible" : "Broken";
				}
			}
			
			
		
			outFile.println("Case #" + i + ": " + out);
		}
		
		
		outFile.close();
		inputFile.close();
	}
	
	
	
	public static String[] tokenize(String input)
	{
		StringTokenizer st = new StringTokenizer(input);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	public static String[] tokenize(String input, String sep)
	{
		StringTokenizer st = new StringTokenizer(input , sep);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	
}

