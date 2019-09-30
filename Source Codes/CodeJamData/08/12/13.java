import java.util.*;
import java.io.*;
public class R1BMain {
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		//BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		Scanner in = new Scanner(new File("R1B-large.in"));
		PrintWriter out = new PrintWriter(new File("R1B-large.out"));
		
		int cas = in.nextInt();
		
		outer: for(int iii = 0; iii < cas; iii++)
		{
			int N = in.nextInt();
			boolean malted[] = new boolean[N];
			Arrays.fill(malted, false);
			
			int nmalted = 0;
			
			int M = in.nextInt();
			int maltedLike[] = new int[M];
			Arrays.fill(maltedLike, -1);
			
			int likes[][] = new int[M][];
			int numLikes[] = new int[M];
			
			TreeSet<Integer> q = new TreeSet<Integer>();
			
			for(int i = 0; i < M; i++)
			{
				int T = in.nextInt();
				likes[i] = new int[T];
				numLikes[i] = T;
				for(int j = 0; j < T; j++)
				{
					likes[i][j] = in.nextInt()-1;
					if(in.nextInt() == 1)
					{
						maltedLike[i] = likes[i][j];
						likes[i][j] = -1;
						numLikes[i]--;
					}
				}
				if(numLikes[i] == 0)
				{
					if(!q.contains(maltedLike[i]))
						q.add(maltedLike[i]);
				}
			}
			
			
			
			while(!q.isEmpty())
			{
				int current = q.first();
				q.remove(current);
				
				nmalted++;
				malted[current] = true;
				
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < likes[i].length; j++)
					{
						if(current == likes[i][j])
						{
							likes[i][j] = -1;
							numLikes[i]--;
							if(numLikes[i] == 0)
							{
								if(maltedLike[i] < 0)
								{
									out.println("Case #" + (iii+1) + ": IMPOSSIBLE");
									continue outer;
								}
								else
								{
									if(!malted[maltedLike[i]])
									{
										q.add(maltedLike[i]);
									}
								}
							}
						}
					}
				}
			}
			
			out.print("Case #" + (iii+1) + ":");
			for(int i = 0; i < N; i++) out.print(" " + (malted[i]?1:0));
			out.println();
			
			
		}
		in.close();
		out.close();
	}
}