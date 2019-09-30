import java.util.*;
import java.io.*;
public class R1MainA {
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		//BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		Scanner in = new Scanner(new File("R1A-large.in"));
		PrintWriter out = new PrintWriter(new File("R1A-large.out"));
		
		int cas = in.nextInt();
		
		for(int iii = 0; iii < cas; iii++)
		{
			int N = in.nextInt();
			
			long ar1[] = new long[N];
			long ar2[] = new long[N];
			
			for(int i = 0; i < N; i++)
				ar1[i] = in.nextLong();
			for(int i = 0; i < N; i++)
				ar2[i] = in.nextLong();
			
			
			Arrays.sort(ar1);
			Arrays.sort(ar2);
			
			long acc = 0;
			
			for(int i = 0; i < N; i++)
				acc += ar1[i]*ar2[N-1-i];
			
			out.println("Case #" + (iii+1) + ": " + acc);
		}
		in.close();
		out.close();
	}
}
