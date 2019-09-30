import java.io.*;
import java.util.*;

public class B implements Runnable
{	
	private String IFILE = "B-large.in"; 
	//private String IFILE = "input.txt";
	private Scanner in;
	private PrintWriter out;
	
	private class T
	{
		public String s;
		public int v;
		public T(String s, int v)
		{
			this.s = s;
			this.v = v;
		}
	}
	
	HashMap<String, Integer> wordsPos;
	
	private T get(int len, String[] w, String mask, char[] seq, int pos)
	{
		int n = w.length;
		if (n == 1)
			return new T(w[0], 0);
		char c = seq[pos];
		String cc = "" + c;
		boolean hasC = false;
		for(int i = 0; i < n; i++)
			if (w[i].contains(cc))
			{
				hasC = true;
				break;
			}
		if (hasC)
		{
			String[] newMasks = new String[n];
			for(int i = 0; i < n; i++)
			{
				char[] p = mask.toCharArray();
				for(int j = 0; j < len; j++)
					if (w[i].charAt(j) == c)
						p[j] = '+';
				newMasks[i] = new String(p);				
			}
			
			boolean[] f = new boolean[n];
			T max = null;
			for(int i = 0; i < n; i++)
				if (!f[i])
				{
					String m = newMasks[i];
					List<String> newList = new ArrayList<String>();
					for(int j = i; j < n; j++)
						if (m.compareTo(newMasks[j]) == 0)
						{
							newList.add(w[j]);
							f[j] = true;
						}
					T v = get(len, newList.toArray(new String[] {}), m, seq, pos + 1);
					if (!w[i].contains(cc))
						v.v++;
					if (max == null || max.v < v.v)
						max = v;
					else if (max.v == v.v)
					{
						int posM = wordsPos.get(max.s);
						int posV = wordsPos.get(v.s);
						if (posV < posM)
							max = v;
					}
				}	
				
			return max;
		}
		else
			return get(len, w, mask, seq, pos + 1);
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ":");
			int n = in.nextInt();
			int m = in.nextInt();
			String[] words = new String[n];
			in.nextLine();
			int maxLen = 0;
			for(int i = 0; i < n; i++)
			{
				words[i] = in.nextLine();
				maxLen = Math.max(maxLen, words[i].length());
			}
			maxLen++;
			for(int i = 0; i < n; i++)
				while (words[i].length() < maxLen)
					words[i] = words[i] + " ";
			
			wordsPos = new HashMap<String, Integer>();
			for(int i = 0; i < n; i++)
				wordsPos.put(words[i], i);
			
			String mask = "";
			for(int i = 0; i < maxLen; i++)
				mask += " ";
			for(int t = 0; t < m; t++)
			{
				char[] seq = (" " + in.nextLine()).toCharArray();
				T res = get(maxLen, words, mask, seq, 0);
				out.print(" " + res.s.trim());
			}
			out.println();
		}
		
		in.close();
		out.close();
	}
	
	public void run()
	{
		try		
		{
			Run();
		}
		catch(IOException e)
		{
			
		}
	}

	public static void main(String[] args) throws IOException
	{
		new B().Run();
		//new Thread(new XXX()).start();
	}

}
