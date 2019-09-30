import java.io.*;
import java.util.*;

public class AlienSmall {
	static String[] dic;
	static ArrayList<ArrayList<String>> allList;
	static int l,d,n;
	
	private static void split(String test)
	{
		allList = new ArrayList<ArrayList<String>>();
		ArrayList<String> list = new ArrayList<String>();
		int i;
		boolean inPara = false;
		for (i=0;i<test.length();i++)
		{
			if (test.charAt(i)=='(')
			{
				inPara = true;
			}
			else if (test.charAt(i)==')')
			{
				inPara = false;
				allList.add(list);
				list = new ArrayList<String>();
			}
			else 
			{
				list.add(test.charAt(i)+"");
				if (!inPara)
				{
					allList.add(list);
					list = new ArrayList<String>();
				}
			}
		}
	}
	
	private static int solve()
	{
		int solution[] = new int[d];
		int total = 0;
		int i,j;
		for (i=0;i<allList.size();i++)
		{
			boolean b[] = new boolean[26];
			for (j=0;j<allList.get(i).size();j++)
			{
				b[allList.get(i).get(j).charAt(0)-97] = true;
			}
			for (j=0;j<d;j++)
			{
				if (b[dic[j].charAt(i)-97])
				{
					if (i==0)
					{
						solution[j] = 1;
					}
				}
				else
				{
					solution[j] = 0;
				}
			}
		}
		for (i=0;i<d;i++)
		{
			total += solution[i];
		}
		return total;
	}
	
	public static void main(String args[])
	{
		try
		{
			BufferedReader reader = new BufferedReader(new FileReader("src/A-large.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("output"));
			String[] tokens = reader.readLine().split(" ");
			l = Integer.parseInt(tokens[0]);
			d = Integer.parseInt(tokens[1]);
			n = Integer.parseInt(tokens[2]);
			int i;
			dic = new String[d];
			for (i=0;i<d;i++)
			{
				dic[i] = reader.readLine();
			}
			for (i=0;i<n;i++)
			{
				String test = reader.readLine();
				split(test);
				writer.write("Case #"+(i+1)+": "+solve());
				writer.newLine();
			}
			reader.close();
			writer.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
