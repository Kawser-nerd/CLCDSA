import java.io.*;
import java.util.*;

public class Main {

	Scanner in;
	PrintWriter out;
	
	String IFILE = "a-large.in";
	String OFILE = "a-large.out";
	
	public void run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter(OFILE);
		
		int nt = in.nextInt();
		for (int it=0; it<nt; it++)
		{
			int p = in.nextInt();
			int k = in.nextInt();
			int l = in.nextInt();
			long[] mas = new long[l];
			for (int i=0; i<l; i++) mas[i] = in.nextLong();
			
			Arrays.sort(mas);
			
			long ans=0;
			int ck = 0;
			int col = 1;
			for (int i=l-1; i>=0; i--)
			{
				if (ck == k)
				{
					ck = 0;
					col++;
				}
				
				ans += mas[i]*col;
				ck++;
			}
			
			out.println("Case #"+(it+1)+": "+ans);
		}
		
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

}
