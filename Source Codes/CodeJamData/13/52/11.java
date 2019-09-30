import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Point2D.Double;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {
	static int N;
	static Point2D[] a;
	static int[] p, best;
	static double max = 0;
	
	public static void main(String[] args) throws FileNotFoundException {
		InputReader r = new InputReader("B.in");
		PrintWriter out = new PrintWriter("B.out");
		
		int T = r.nextInt();
		int caseNumber = 1;
		
		while(T-- > 0){
			max = 0;
			best = null;
			
			N = r.nextInt();
			
			p = new int[N];
			a = new Point2D[N];
			for(int i = 0; i < N; i++){
				int x = r.nextInt();
				int y = r.nextInt();
				
				a[i] = new Point2D.Double(x, y);
			}
			
			perm(0, new boolean[N]);

			out.printf("Case #%d:", caseNumber++);
			for(int x = 0; x < N; x++)
				out.print(" " + (best[x]));
			out.println();
		}
		out.close();
	}
	
	private static void perm(int i, boolean[] v) {
		if(i == N){
//			System.out.println(Arrays.toString(p));
			for(int x = 0; x < N; x++)
			for(int y = x + 2; y + (x == 0 ? 1 : 0) < N; y++){
				Line2D.Double line1 = new Line2D.Double(a[p[x]], a[p[(x + 1) % N]]);
				Line2D.Double line2 = new Line2D.Double(a[p[y]], a[p[(y + 1) % N]]);
				
//				System.out.println(line1 + ", " + line2);
				
				if(line1.intersectsLine(line2))return;
			}
			
			double area = 0;
			
			for(int x = 1; x < N - 1; x++)
				area += cross(a[p[0]], a[p[x]], a[p[x + 1]]);
			area /= 2;
			area = Math.abs(area);
//			System.out.println(area);
			if(area > max){
				max = area;
				best = p.clone();
			}
		}else{
			for(int x = 0; x < N; x++)if(!v[x]){
				v[x] = true;
				p[i] = x;
				perm(i + 1, v);
				v[x] = false;
			}
		}
	}
	
	private static double cross(Point2D a, Point2D b,
			Point2D c) {
		Point2D ab = new Point2D.Double(b.getX() - a.getX(), b.getY() - a.getY());
		Point2D ac = new Point2D.Double(c.getX() - a.getX(), c.getY() - a.getY());
		
		return ab.getX() * ac.getY() - ac.getX() * ab.getY();
	}

	static double cross(Double a2, Double a3, Double a4){
		return 0;
	}

//	static class P{
//		int x, y;
//		public P(int xi, int yi){
//			x = xi;
//			y = yi;
//		}
//	}
	static class InputReader {
	    private BufferedReader reader;
	    private StringTokenizer tokenizer;

	    public InputReader(String fileName) throws FileNotFoundException {
	        reader = new BufferedReader(new FileReader(fileName));
	        tokenizer = null;
	    }

	    public String nextLine(){
	    	try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
	    }
	    public String next() {
	        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                tokenizer = new StringTokenizer(reader.readLine());
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }
	        return tokenizer.nextToken();
	    }

	    public int nextInt() {
	        return Integer.parseInt(next());
	    }
	    public long nextLong() {
	        return Long.parseLong(next());
	    }
	}
	
}
