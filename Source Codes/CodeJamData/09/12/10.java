import java.util.*;

import static java.lang.Math.*;

public class B 
{
	void p(String s)
	{
		System.out.println(s);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int C = sc.nextInt();
		for(int zz=1;zz<= C;zz++)
		{
			N = sc.nextInt();
			M = sc.nextInt();
			S = new int[M][N];
			W = new int[M][N];
			T = new int[M][N];
			for(int i = 0; i < N;i++)
			{
				for(int j = 0; j < M;j++)
				{
					S[j][N-i-1] = sc.nextInt();
					W[j][N-i-1] = sc.nextInt();
					T[j][N-i-1] = sc.nextInt();
				}
			}
			PriorityQueue<Node> pq = new PriorityQueue<Node>();
			Node[][][][] v = new Node[M][N][2][2];
			for(int a = 0; a < v.length;a++)
				for(int b = 0; b < v[0].length;b++)
					for(int c = 0; c < v[0][0].length;c++)
						Arrays.fill(v[a][b][c],null);
			Node st = new Node(0,0,0,0,0);
			pq.add(st);
			long ans = 0;
			while(pq.size() > 0)
			{
				Node n = pq.poll();
				Node old = v[n.iX][n.iY][n.cX][n.cY];
				if(old != null && old.time <= n.time)
					continue;
				v[n.iX][n.iY][n.cX][n.cY] = n;
				if(n.iX == M-1 && n.iY == N-1 && n.cX == 1 && n.cY == 1)
				{
					ans = n.time;
					break;
				}
				if(n.cX == 0 && n.cY == 0)
				{
					add(pq,new Node(n.iX -1, n.iY, 1,0,n.time+2));
					add(pq,new Node(n.iX , n.iY-1, 0,1,n.time+2));
					add(pq,new Node(n.iX , n.iY, 0,1,n.time+1+wait(n.iX,n.iY,true,n.time)));
					add(pq,new Node(n.iX , n.iY, 1,0,n.time+1+wait(n.iX,n.iY,false,n.time)));
				}
				else if(n.cX == 0 && n.cY == 1)
				{
					add(pq,new Node(n.iX -1, n.iY, 1,1,n.time+2));
					add(pq,new Node(n.iX , n.iY+1, 0,0,n.time+2));
					add(pq,new Node(n.iX , n.iY, 0,0,n.time+1+wait(n.iX,n.iY,true,n.time)));
					add(pq,new Node(n.iX , n.iY, 1,1,n.time+1+wait(n.iX,n.iY,false,n.time)));
				}
				else if(n.cX == 1 && n.cY == 0)
				{
					add(pq,new Node(n.iX +1, n.iY, 0,0,n.time+2));
					add(pq,new Node(n.iX , n.iY-1, 1,1,n.time+2));
					add(pq,new Node(n.iX , n.iY, 1,1,n.time+1+wait(n.iX,n.iY,true,n.time)));
					add(pq,new Node(n.iX , n.iY, 0,0,n.time+1+wait(n.iX,n.iY,false,n.time)));
				}
				else if(n.cX == 1 && n.cY == 1)
				{
					add(pq,new Node(n.iX +1, n.iY, 0,1,n.time+2));
					add(pq,new Node(n.iX , n.iY+1, 1,0,n.time+2));
					add(pq,new Node(n.iX , n.iY, 1,0,n.time+1+wait(n.iX,n.iY,true,n.time)));
					add(pq,new Node(n.iX , n.iY, 0,1,n.time+1+wait(n.iX,n.iY,false,n.time)));
				}
			}
			System.out.println("Case #"+zz+": "+ans);
		}


	}
	private static long wait(int iX, int iY, boolean vert, long time) 
	{
		int S1 = S[iX][iY];
		int W1 = W[iX][iY];
		int T1 = T[iX][iY];
		
		long d;
		if(time > T1)
		{
			d = (time-T1)%(S1+W1);
		}else{
			d = ((S1+W1)-((T1-time)%(S1+W1)))%(S1+W1);
		}
		
		//System.out.println(iX+" "+iY+" "+vert+" "+time+" "+d+" "+S1+" "+W1+" "+T1);
		long ans;
		if(vert)
		{
			if(d < S1)
				ans = 0;
			else 
				ans = (S1+W1)-d;
		}
		else
		{
			if(d >= S1)
				ans =  0;
			else
				ans =  S1-d;
		}
		//System.out.println(ans);
		return ans;
	}
	private static void add(PriorityQueue<Node> pq, Node a) 
	{
		if(a.iX < 0 || a.iY < 0 || a.iX >= M || a.iY >= N)
			return;
		pq.add(a);
	}
	private static class Node implements Comparable<Node>
	{
		int iX,iY;
		int cX,cY;
		long time = 0;
		Node(int a, int b, int c, int d, long l)
		{
			iX = a;
			iY = b;
			cX = c;
			cY = d;
			time = l;
		}
		public int compareTo(Node a) 
		{
			return Long.valueOf(time).compareTo(a.time);
		}
	}
	static int N,M;
	static int[][] S,W,T;
}
