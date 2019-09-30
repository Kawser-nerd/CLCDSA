import java.util.*;
import java.io.*;
public class R1B {
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintStream out = new PrintStream(new File("B-large.out"));
		int cas = in.nextInt();
		
		for(int iii = 0; iii < cas; iii++)
		{
			int N = in.nextInt();
			int K = in.nextInt();
			int B = in.nextInt();
			int T = in.nextInt();
			int pos[] = new int[N];
			int speed[] = new int[N];
			for(int i = 0; i < N; i++) pos[i] = B-in.nextInt();
			for(int i = 0; i < N; i++) speed[i] = in.nextInt();
			
			for(int i = 0; i < N; i++) pos[i] = ((pos[i]-1)/speed[i])+1;
			
			int count = 0;
			int seen = 0;
			int done = 0;
			
			for(int i = N-1; i >= 0; i--)
			{
				if(pos[i] > T)
				{
					seen++;
				}
				else
				{
					count += seen;
					done++;
					if(done == K) break;
				}
			}
			
			out.println("Case #" + (iii+1) + ": " + (done >= K ? ""+count: "IMPOSSIBLE"));	
		}
		
		out.close();
	}
}