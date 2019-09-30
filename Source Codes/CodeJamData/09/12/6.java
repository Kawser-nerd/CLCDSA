import java.io.*;
import java.util.*;

public class B
{
	public static void main(String[] arg)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int C=1; C<=T; ++C)
		{
			System.out.printf("Case #%d: ", C);
			(new B(sc)).caseMain();
		}
	}

	Scanner sc;
	B( Scanner sc ) { this.sc = sc; }

	void caseMain()
	{
		int Y = sc.nextInt();
		int X = sc.nextInt();
		long[][] S = new long[Y][X];
		long[][] W = new long[Y][X];
		long[][] T = new long[Y][X];
		for(int y=0; y<Y; ++y)
			for(int x=0; x<X; ++x)
			{
				S[y][x] = sc.nextInt();
				W[y][x] = sc.nextInt();
				T[y][x] = sc.nextInt();
			}
		System.out.printf("%d\n", solve(Y, X, S, W, T));
	}

	long solve(final int Y, final int X, long[][] S, long[][] W, long[][] T)
	{
		class State implements Comparable<State>
		{
			long t;
			int y, x;
			int id() { return y*(2*X) + x; }
			State(long t, int y, int x){this.t=t; this.y=y; this.x=x;}

			public int compareTo(State rhs) {
				if( t < rhs.t ) return -1;
				if( t > rhs.t ) return +1;
				if( y < rhs.y ) return -1;
				if( y > rhs.y ) return +1;
				if( x < rhs.x ) return -1;
				if( x > rhs.x ) return +1;
				return 0;
			}
		}

		PriorityQueue<State> Q = new PriorityQueue<State>();
		Q.add( new State(0, 2*(Y-1)+1, 0) );

		Set<Integer> visited = new HashSet<Integer>();

		while( !Q.isEmpty() )
		{
			State s = Q.poll();
			if( visited.contains(s.id()) )
				continue;
			visited.add(s.id());

			if( s.y==0 && s.x==2*(X-1)+1 )
				return s.t;


			int[] dy={-1,+1,0,0};
			int[] dx={0,0,-1,+1};
			for(int i=0; i<4; ++i)
			{
				int y2=s.y+dy[i], x2=s.x+dx[i];
				if( y2<0 || 2*Y<=y2 || x2<0 || 2*X<=x2 )
					continue;
				if( visited.contains(y2*(2*X)+x2) )
					continue;
				long t2 = s.t;
				if( s.x!=x2 && s.x/2!=x2/2 ) t2 += 2;
				else if( s.y!=y2 && s.y/2!=y2/2 ) t2 += 2;
				else if( s.x!=x2 )
				{
					long Si = S[y2/2][x2/2];
					long Wi = W[y2/2][x2/2];
					long Ti = T[y2/2][x2/2] % (Si+Wi) - (Si+Wi);
					long d = (s.t - Ti) % (Si+Wi);
					if( d < Si ) t2 += (Si-d)+1;
					else t2 += 1;
				}
				else //if(y!=y2)
				{
					long Si = S[y2/2][x2/2];
					long Wi = W[y2/2][x2/2];
					long Ti = T[y2/2][x2/2] % (Si+Wi) - (Si+Wi);
					long d = (s.t - Ti) % (Si+Wi);
					if( d < Si ) t2 += 1;
					else t2 += (Si+Wi-d)+1;
				}
				Q.add( new State(t2, y2, x2) );
			}
		}
		return -1;
	}
}
