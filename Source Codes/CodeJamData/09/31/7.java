import java.io.*;
import java.util.*;

public class A implements Runnable
{	
	private String IFILE = "A-large.in";
	private Scanner in;
	private PrintWriter out;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		in.nextLine();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			char[] c = in.nextLine().toCharArray();
			int n = c.length;
			HashMap<Character, Integer> map = new HashMap<Character, Integer>();
			map.put(c[0], 1);
			boolean[] mas = new boolean[1000];
			mas[1] = true;
			int ss = 1;
			for(int i = 1; i < n; i++)
			{
				if (!map.containsKey(c[i]))
				{
					for(int j = 0; j < 1000; j++)
						if (!mas[j])
						{
							ss = Math.max(j, ss);
							mas[j] = true;
							map.put(c[i], j);
							break;
						}							
				}
			}
			ss++;
			long result = 0;
			for(int i = 0; i < n; i++)
			{
				result *= ss;
				result += map.get(c[i]);
			}
			out.println(result);
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
		new A().Run();
		//new Thread(new XXX()).start();
	}

}
