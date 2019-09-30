/* Andy Rock
 * April 15, 2016
 * 
 * Round 1A 2016: Problem C. 
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class C
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader("C.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C.out"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			int[] F = new int[N];
			for(int i=0;i<N;i++)
				F[i] = Integer.parseInt(st.nextToken())-1;

			List<List<Integer>> rev = new ArrayList<List<Integer>>();
			for(int i=0;i<N;i++)
				rev.add(new ArrayList<Integer>());

			for(int i=0;i<N;i++)
				rev.get(F[i]).add(i);

			int a1 = 0;
			for(int i=0;i<N;i++)
				if(F[F[i]] == i && i < F[i])
				{
					int[] dist = new int[N];
					Arrays.fill(dist, Integer.MAX_VALUE);
					dist[i] = 1;
					dist[F[i]] = 0;

					Queue<Integer> q = new LinkedList<Integer>();
					q.offer(i);
					int t1 = 0;
					while(!q.isEmpty())
					{
						int curr = q.poll();
						t1 = dist[curr];

						for(int next : rev.get(curr))
							if(dist[next] == Integer.MAX_VALUE)
							{
								dist[next] = dist[curr]+1;
								q.offer(next);
							}
					}

					Arrays.fill(dist, Integer.MAX_VALUE);
					dist[F[i]] = 1;
					dist[i] = 0;

					q.offer(F[i]);
					int t2 = 0;
					while(!q.isEmpty())
					{
						int curr = q.poll();
						t2 = dist[curr];

						for(int next : rev.get(curr))
							if(dist[next] == Integer.MAX_VALUE)
							{
								dist[next] = dist[curr]+1;
								q.offer(next);
							}
					}

					a1 += t1+t2;
				}

			int a2 = 0;
			for(int i=0;i<N;i++)
			{
				boolean[] vis = new boolean[N];
				int curr = F[i], dist = 1;
				while(!vis[curr])
				{
					vis[curr] = true;
					if(curr == i)
						a2 = Math.max(a2, dist);
					curr = F[curr];
					dist++;
				}
			}

			out.write("Case #"+t+": "+Math.max(a1, a2)+"\n");
		}

		in .close();
		out.close();
	}
}