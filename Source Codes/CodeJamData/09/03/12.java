import java.io.*;

public class Welcome {
	
	static int current[];
	
	static void inc(int index)
	{
		current[index] = (current[index]+1)%10000;
	}
	
	static void move(int index)
	{
		current[index+1] = (current[index]+current[index+1])%10000;
	}
	
	private static int solve(String line)
	{
		String wel = "welcome to code jam";
		int length = wel.length();
		current =new int[length];
		int i,j;
		for (i=0;i<line.length();i++)
		{
			char c = line.charAt(i);
			for (j=0;j<length;j++)
			{
				if (c==wel.charAt(j))
				{
					if (j>0)
					{
						move(j-1);
					}
					else
					{
						inc(j);
					}
				}
			}
		}
		return current[length-1];
	}
	
	public static void main(String args[])
	{
		try
		{
			BufferedReader reader = new BufferedReader(new FileReader("src/C-large.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("output"));
			int n = Integer.parseInt(reader.readLine());
			int i;
			for (i=0;i<n;i++)
			{
				String line = reader.readLine();
				int result = solve(line);
				writer.write("Case #"+(i+1)+": ");
				if (result<1000)
				{
					writer.write("0");
				}
				if (result<100)
				{
					writer.write("0");
				}
				if (result<10)
				{
					writer.write("0");
				}
				writer.write(result+"");
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
