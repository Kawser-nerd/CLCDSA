//input file must be "in.txt"
//output file is "out.txt"
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class B
{
	public static void main(String[] args)throws Throwable
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		
		int t = in.nextInt();
		in.nextLine();
		
		for (int c = 1; c <= t; c++)
		{
			out.print("Case #");
			out.print(c);
			out.print(": ");
			out.println(getSolution(in));
		}
		
	}
	private static String getSolution(Scanner in)
	{
		int numWords;
		int numLists;
		numWords = in.nextInt();
		numLists = in.nextInt();
		
		in.nextLine();
		
		Word[] words = new Word[numWords];
		String[] lists = new String[numLists];
		
		for (int i = 0; i < numWords; i++)
		{
			words[i] = new Word();
			words[i].word = in.nextLine();
			words[i].empty();
			words[i].index = i;
		}
		
		
		
		for (int i = 0; i < numLists; i++)
		{
			lists[i] = in.nextLine();
		}
		
		StringBuffer result = new StringBuffer();
		
		for (int i = 0; i < lists.length; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				Arrays.sort(words);
				boolean contains;
				int index = 0;
				char c = lists[i].charAt(j);
				contains = words[0].word.contains(Character.toString(c));
				//System.out.println(c);
				for (int k = 1; k < words.length; k++)
				{
					if (words[index].unknown.equals(words[k].unknown))
					{
						if (!contains)
							contains = words[k].word.contains(Character.toString(c));
					}
					else 
					{
						if(contains)
						{
							for (int l = index; l < k; l++)
							{
								words[l].fill(c);
							}
						}
						contains = words[k].word.contains(Character.toString(c));;
						index = k;
						
					}
				}
				if (contains)
				{
					for (int l = index; l < words.length; l++)
					{
						words[l].fill(c);
					}
				}
			}
			
			int max = 0;
			int maxIndex = 0;
			for (int j = 0; j < words.length; j++)
			{
				if (words[j].points > max || (words[j].points == max && words[j].index < words[maxIndex].index))
				{
					max = words[j].points;
					maxIndex = j;
				}
				words[j].empty();
			}
			result.append(words[maxIndex].word);
			result.append(' ');
		}
		return result.toString();
		
	}
	public static class Word implements Comparable<Word>
	{
		public String word;
		public String unknown;
		public int points;
		public int index;
		public int compareTo(Word w) 
		{
			return unknown.compareTo(w.unknown);
		}
		public void fill(char c)
		{
			//System.out.println("Filling " + word + ": " + unknown + ", " + c);
			StringBuffer sb = new StringBuffer();
			boolean changed = false;
			for (int i = 0; i < word.length(); i++)
			{
				if (word.charAt(i) == c)
				{
					changed = true;
					sb.append(c);
				}
				else
				{
					sb.append(unknown.charAt(i));
				}
			}
			
			unknown = sb.toString();
			if (!changed)
				points++;
		}
		public void empty()
		{
			//System.out.println("Emptying " + word + ": " + points);
			StringBuffer sb = new StringBuffer();
			for (int i = 0; i < word.length(); i++)
			{
				sb.append("_");
			}
			
			unknown = sb.toString();
			points = 0;
		}
	}
}
