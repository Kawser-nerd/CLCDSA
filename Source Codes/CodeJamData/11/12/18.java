package jam2011;
import java.io.*;
import java.util.*;

// Marian G Olteanu
// round 1A
public class AB
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
			int n = Integer.parseInt(lineT[0]);
			int m = Integer.parseInt(lineT[1]);
			
			String[] words = new String[n];
			for (int j = 0; j < words.length; j++)
				words[j] = inputFile.readLine();
			
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < m; j++)
			{
				String list = inputFile.readLine();
				String selectedWord = getCostliestWord(list , words);
				sb.append(' ').append(selectedWord);
			}
			
			outFile.println("Case #" + i + ":" + sb.toString());
		}
		
		
		outFile.close();
		inputFile.close();
	}
	
	private static String getCostliestWord(String list, String[] words)
	{
		//System.out.println(list);
		int maxCost = -1;
		String selectedWord = null;
		for (int i = 0; i < words.length; i++)
		{
			int cost = getCost(list , words, words[i]);
			if (cost > maxCost)
			{
				maxCost = cost;
				selectedWord = words[i];
			}
		}
		return selectedWord;
	}
	
	private static int getCost(String list, String[] words , String word)
	{
		boolean[] activeWords = new boolean[words.length];
		int cost = 0;
		
		for (int i = 0; i < activeWords.length; i++)
			activeWords[i] = words[i].length() == word.length();
		
		int i = 0;
		while (true)
		{
			int cntActive = countTrue(activeWords);
			//System.out.println("Active: " + cntActive);
			if (cntActive == 1)
				return cost;// now Sean knows the word
			
			// select candidate next letter
			while (!goodLetter(list.charAt(i) , words, activeWords))
				i++;
			
			// now try letter
			char c = list.charAt(i);
			if (word.indexOf(c) == -1)
			{
				// missed
				cost++;
				// from the active list, remove all with character c
				for (int j = 0; j < words.length; j++)
					if (activeWords[j])
						if (words[j].indexOf(c) != -1)
							activeWords[j] = false;
			}
			else
			{
				// good try, filter those that don't match letter c with selected word
				for (int j = 0; j < words.length; j++)
					if (activeWords[j])
						for (int k = 0; k < word.length(); k++)
						{
							boolean b1 = word.charAt(k) == c;
							boolean b2 = words[j].charAt(k) == c;
							if (b1 != b2)
							{
								activeWords[j] = false;
								break;
							}
						}
			}
			// move to next letter
			i++;
		}
	}
	
	// is any of the active words containing the character c?
	private static boolean goodLetter(char c, String[] words, boolean[] activeWords)
	{
		for (int i = 0; i < words.length; i++)
			if (activeWords[i])
				if (words[i].indexOf(c) != -1)
					return true;
		return false;
	}
	
	private static int countTrue(boolean[] array)
	{
		int count = 0;
		for (boolean b : array)
			if (b)
				count++;
		return count;
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

