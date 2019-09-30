import java.util.*;
import java.io.*;
public class R1CMain {
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		//BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		Scanner in = new Scanner(new File("R1C-small.in"));
		Scanner in2 = new Scanner(new File("R1C-calc"));
		PrintWriter out = new PrintWriter(new File("R1C-small.out"));
		
		int cas = in.nextInt();
		
		String ans[] = new String[31];
		for(int i = 1; i <= 30; i++)
			ans[i] = in2.next();
		
		outer: for(int iii = 0; iii < cas; iii++)
		{
			int N = in.nextInt();
	out.println("Case #" + (iii+1) + ": " + ans[N]);
		}
		in.close();
		out.close();
	}
}
