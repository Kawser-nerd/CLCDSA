import java.util.*;
import java.io.*;
 
class Main {
	void solve () {
		
		//?????????????
		int h = nextInt(), w = nextInt();

		//start,goal?????
		int sy = nextInt()-1, sx = nextInt()-1, gy = nextInt()-1, gx = nextInt()-1;
		Point start = new Point(sx, sy), goal = new Point(gx, gy);

		//???????
		char[][] map = nextChar2DArray(h, w, false); //true?????????

		//Queue???????????????
		ArrayDeque<Point> dq = new ArrayDeque<>();
		dq.add(start);

		//?????????????????????????
		int[][] moves = new int[h][w];

		//???????"#"????????????
		map[start.getY()][start.getX()] = '#';


		//?????
		while (dq.size() > 0) {

			//Queue???????????????????????????
			Point p = dq.removeFirst();

			for (int i=0; i<4; i++) {

				int x = p.getX()+D4[i].getX();
				int y = p.getY()+D4[i].getY();

				if (map[y][x] == '.') {

					//"."????????????Queue????????
					dq.addLast(new Point(x, y));

					//??????????"#"???????????????????
					map[y][x] = '#';

					//??p??p??????????????p???????+1
					moves[y][x] = moves[p.getY()][p.getX()] + 1;

				}

			}

		}


		//??????????moves?????
		out.println(moves[goal.getY()][goal.getX()]);
		
	}
	
	
	static void printInt2DArray (int[][] ar) {
		for (int i=1; i<ar.length-1; i++) {
			for (int j=1; j<ar[0].length-1; j++) {
				if (ar[i][j] == 0) {
					out.print("## ");
				}
				else {
					out.print(String.format("%02d",ar[i][j]) + " ");
				}
				
			}
			out.println();
		}
	}
 
 
	// <Main Method>
	public static PrintWriter out;
	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}
 
	// <Default Field>
	Point[] D4 = {new Point(0,-1), new Point(1,0), new Point(0,1), new Point(-1,0)};
	static int MAX_INT = Integer.MAX_VALUE, MIN_INT = Integer.MIN_VALUE;
	static double PI = Math.PI;
	static int MOD = 1000000007;
 
	// <Default Method>
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static int calcManhatDistance (int x1, int y1, int x2, int y2) {
		int d = Math.abs(x1-x2)+Math.abs(y1-y2);
		return d;
	}
	static double calcEuclidDistance (double x1, double y1, double x2, double y2) {
		double d = Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		return d;
	}
	static boolean isPrime (int n) {
		if (n==2) return true;
		if (n<2 || n%2==0) return false;
		double d = Math.sqrt(n);
		for (int i=3; i<=d; i+=2) if(n%i==0){return false;}
		return true;
	}
	static void printChar2DArray (char[][] ar) {
		for (int i=0; i<ar.length; i++) {
			for (int j=0; j<ar[0].length; j++) {
				out.print(ar[i][j]);
			}
			out.println();
		}
	}
	static void printIntArray (int[] ar) {
		for (int i=0; i<ar.length; i++) {
			out.print((i==0?"":" ")+ar[i]);
		}
		out.println();
	}
	static void printlnIntArray (int[] ar) {
		for (int i=0; i<ar.length; i++) {
			out.println(ar[i]);
		}
	}
	static int[] cumsumIntArray (int[] ar) {
		for (int i=1; i<ar.length; i++) {
			ar[i] += ar[i-1];
		}
		return ar;
	}
	static int minIntArray (int[] ar) {
		int min = MAX_INT;
		for (int i=0; i<ar.length; i++) {
			min = Math.min(min, ar[i]);
		}
		return min;
	}
	static int maxIntArray (int[] ar) {
		int max = MIN_INT;
		for (int i=0; i<ar.length; i++) {
			max = Math.max(max, ar[i]);
		}
		return max;
	}
 
	// <Fast Scanner> START -------------------------------------------------
	static InputStream in = System.in;
	static  byte[] buffer = new byte[1024];
	static int length = 0, p = 0;
	public static boolean hasNextByte () {
		if (p < length) return true;
		else {
			p = 0;
			try {length = in.read(buffer);}
			catch (Exception e) {e.printStackTrace();}
			if (length <= 0) return false;
		}
		return true;
	}
	public static int readByte () {
		if (hasNextByte() == true) return buffer[p++];
		return -1;
	}
	public static boolean isPrintable (int n) {return 33<=n&&n<=126;}
	public static void skip () {
		while (hasNextByte() && !isPrintable(buffer[p])) p++;
	}
	public static boolean hasNext () {skip(); return hasNextByte();}
	public static String next () {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int temp = readByte();
		while (isPrintable(temp)) {
			sb.appendCodePoint(temp);
			temp = readByte();
		}
		return sb.toString();
	}
	public static String[] nextStringArray (int n) {
		String[] ar = new String[n];
		for (int i=0; i<n; i++) ar[i] = next();
		return ar;
	}
	public static int nextInt () {return Math.toIntExact(nextLong());}
	public static int[] nextIntArray (int n) {
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = nextInt();
		return ar;
	}
	public static long nextLong () {
		if (!hasNext()) throw new NoSuchElementException();
		boolean minus = false;
		int temp = readByte();
		if (temp == '-') {
			minus = true;
			temp = readByte();
		}
		if (temp<'0' || '9'<temp) throw new NumberFormatException();
		long n = 0;
		while (isPrintable(temp)) {
			if ('0'<=temp && temp<='9') {
				n *= 10;
				n += temp - '0';
			}
			else throw new NumberFormatException();
			temp = readByte();
		}
		return minus? -n : n;
	}
	public static double nextDouble () {
		return Double.parseDouble(next());
	}
	public static char[][] nextChar2DArray (int h, int w, boolean b) {
		char[][] ar = new char[b?h+2:h][b?w+2:w];
		for (int i=b?1:0; i<(b?h+1:h); i++) {
			String temp = next();
			for (int j=0; j<w; j++) {
				ar[i][b?j+1:j] = temp.charAt(j);
			}
		}
		return ar;
	}
	// <Fast Scanner> END ----------------------------------------------------------
}
 
 
 
class Point{
	private int x;
	private int y;
 
	Point(int a, int b) {x=a; y=b;}
 
	int getX() {return x;}
	int getY() {return y;}
	void setX(int n) {x = n;}
	void setY(int n) {y = n;}
}