import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemC {
	class Edge {
		int st, fn;
		int fl, cp;
		Edge next, rev;
		public Edge() {
			this.fl = 0;
			this.cp = 1;
		}
	}
	
	Edge[] adj;
	
	void addEdge(int x, int y) {
		//System.out.println(x+" "+y);
		Edge a = new Edge(), b = new Edge();
		b.cp = 0;
		a.st=x; a.fn=y; b.st=y; b.fn=x;
		a.rev=b; b.rev=a;
		a.next=adj[x]; adj[x]=a;
		b.next=adj[y]; adj[y]=b;
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt(), M = sc.nextInt();
			String[] map = new String[N];
			for (int i=0; i < N; i++)
				map[i] = sc.next();
			adj = new Edge[N*M+2];
			for (int i=0; i < N; i++)
				for (int j=0; j < M; j++)
					if (map[i].charAt(j) == '.')
						if (j % 2 == 0)
							addEdge(0, i*M+j+1);
						else
							addEdge(i*M+j+1, N*M+1);
			for (int i=0; i < N; i++)
				for (int j=0; j < M; j++)
					for (int dx=-1; dx<=1; dx++)
						for (int dy=-1; dy<=1; dy+=2) {
							if (i+dx<0||i+dx>=N||j+dy<0||j+dy>=M||map[i].charAt(j)!='.'||map[i+dx].charAt(j+dy)!='.')
								continue;
							int id1 = i*M+j+1;
							int id2 = (i+dx)*M+j+dy+1;
							if (id1<id2) {
								if (j%2==0) addEdge(id1, id2);
								else addEdge(id2, id1);
							}
						}
			int res = 0;
			int[] q = new int[N*M+2];
			Edge[] prev = new Edge[N*M+2];
			while (true) {
				Arrays.fill(prev, null);
				prev[0] = new Edge();
				int qBeg=0, qEnd=0;
				q[qBeg++] = 0;
				while (qEnd < qBeg) {
					int curV = q[qEnd++];
					Edge cur = adj[curV];
					while (cur != null) {
						if (cur.fl<cur.cp && prev[cur.fn] == null) {
							prev[cur.fn] = cur;
							q[qBeg++] = cur.fn;
						}
						cur = cur.next;
					}
				}
				if (prev[N*M+1]==null) break;
				res++;
				int x = N*M+1;
				while (x!=0) {
					prev[x].fl++;
					prev[x].rev.fl--;
					x = prev[x].st;
				}
			}
			int free=0;
			for (int i=0;i<N;i++)
				for (int j=0;j<M;j++)
					if (map[i].charAt(j)=='.')free++;
			pw.println(free - res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}