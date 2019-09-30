import java.io.*;
import java.util.*;

public class C
{
	public static void main(String[] strings) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.in"))));
		PrintWriter writer = new PrintWriter(new File("output.out"));

		int tc = Integer.parseInt(reader.readLine());

		for(int time = 1 ; time <= tc ; time++)
		{
			StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
			int c = Integer.parseInt(tokenizer.nextToken());
			int d = Integer.parseInt(tokenizer.nextToken());
			long v = Integer.parseInt(tokenizer.nextToken());

			long [] dom = new long[d];
			tokenizer = new StringTokenizer(reader.readLine());
			for(int i = 0 ; i < d ; i++)
				dom[i] = Long.parseLong(tokenizer.nextToken());


			int p = 0;
			long till = 0;
			int res = 0;
			while(till < v)
			{
				if(p >= dom.length || dom[p] > till+1)
					res++;
				else
					p++;
				till += (long)c*(till+1);

				while(p < dom.length && dom[p] <= till)
				{
					till += (long)c*dom[p];
					p++;
				}
			}

			writer.println("Case #"+(time)+": "+(res));
		}

		writer.flush();
		writer.close();
	}
}