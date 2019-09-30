import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
	
		int R = sc.nextInt(), C = sc.nextInt(), N = sc.nextInt();
		Point[] pts = new Point[N << 1];
		int sz = 0;
		for(int i = 0, j = 0; i < N; ++i)
		{
			Point p = new Point(sc.nextInt(), sc.nextInt()), q = new Point(sc.nextInt(), sc.nextInt());
			if(p.onBoundary(R, C) && q.onBoundary(R, C))
			{
				pts[sz << 1] = p;
				pts[sz << 1 | 1] = q;
				p.idx = q.idx = sz++;
			}
		}
		pts = Arrays.copyOf(pts, sz << 1);
		for(int i = 0; i < sz << 1; ++i)
			pts[i].setFrameIndex(R, C);
		Arrays.sort(pts);
		boolean possible = true, open[] = new boolean[sz];
		Stack<Integer> s = new Stack<>();
		for(Point p: pts)
			if(!open[p.idx])
			{
				open[p.idx] = true;
				s.push(p.idx);
			}
			else if(s.pop() != p.idx)
			{
				possible = false;
				break;
			}
		out.println(possible ? "YES" : "NO");
		out.close();
	}
	
	static class Point implements Comparable<Point>
	{
		int x, y, idx, frameIndex;
		
		Point(int a, int b) { x = a; y = b; }
		
		boolean onBoundary(int R, int C) { return x == 0 || x == R || y == 0 || y == C; }
		
		void setFrameIndex(int R, int C)
		{
			if(y == 0)
				frameIndex = x;
			else if(x == R)
				frameIndex = R + y;
			else if(y == C)
				frameIndex = R + C + R - x;
			else
				frameIndex = R + C + R + C - y;
		}
		
		public int compareTo(Point p) { return frameIndex - p.frameIndex; }
	}
		
	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException { return Double.parseDouble(next()); }

		public boolean ready() throws IOException {return br.ready();} 
	}
}