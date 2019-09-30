import java.io.*;
import java.util.*;

public class A implements Runnable
{	
	private String IFILE = "A-large.in";
	private Scanner in;
	private PrintWriter out;
	
	public class Dir
	{
		private String name;
		private List<Dir> subDir;
		
		public Dir(String name)
		{
			this.name = name;
			subDir = new ArrayList<Dir>();
		}
		
		public int mkSubDir(String name)
		{
			for(Dir d : subDir)
				if (d.getName().compareTo(name) == 0)
					return 0;
			subDir.add(new Dir(name));
			return 1;
		}	
		
		public Dir searchDir(String name)
		{
			for(Dir d : subDir)
				if (d.getName().compareTo(name) == 0)
					return d;
			return null;
		}
		
		public int mkPath(String path)
		{
			int index = path.indexOf('/');
			String name;
			if (index == -1)
				name = path;
			else
				name = path.substring(0, index);
			int result = mkSubDir(name);
			if (index >= 0)
			{
				Dir d = searchDir(name);
				result += d.mkPath(path.substring(index + 1));
			}
			return result;
		}
		
		public String getName()
		{
			return name;
		}
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			in.nextLine();
			Dir root = new Dir("");
			for(int i = 0; i < n; i++)
				root.mkPath(in.nextLine().substring(1));
			int result = 0;
			for(int i = 0; i < m; i++)
				result += root.mkPath(in.nextLine().substring(1));
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
