import java.util.*;
public class B {
	static int [] dx = {-1,0,0,1};
	static int [] dy = {0,-1,1,0};
	static int H,W;
	public static void main (String [] arg) throws Throwable {
		int T = nextInt();
		for (int ii = 1; ii<=T; ++ii) {
			H = nextInt();
			W = nextInt();
			int [][] dir = new int [H][W];
			int [][] V = new int [H][W];
			char [][] ans = new char [H][W];
			for (int i = 0; i<H; ++i) for (int j = 0; j<W; ++j) V[i][j] = nextInt();
			for (int i = 0; i<H; ++i) {
				for (int j = 0; j<W; ++j) {
					int bestK = -1;
					int bestV = V[i][j];
					for (int k = 0; k<dx.length; ++k) {
						int x1 = dx[k] + i;
						int y1 = dy[k] + j;
						if (valid(x1,y1) && V[x1][y1] < bestV){bestV=V[x1][y1]; bestK=k;}
					}
					dir[i][j] = bestK;
				}
			}
			char z = 'a';
			for (int i = 0; i<H; ++i) {
				for (int j = 0; j<W; ++j) {
					if (ans[i][j] !=0) continue;
					int z1 = i;
					int z2 = j;
					while (dir[z1][z2] != -1) {
						int k = dir[z1][z2];
						z1 = dx[k] + z1;
						z2 = dy[k] + z2;
					}
					LinkedList<Pair> L = new LinkedList<Pair>();
					L.add(new Pair(z1,z2));
					while (!L.isEmpty()) {
						Pair P = L.remove();
						ans[P.x][P.y] = z;
						for (int k = 0; k<dx.length; ++k) {
							int x1 = dx[k] + P.x;
							int y1 = dy[k] + P.y;
							if (valid(x1,y1) && dir[x1][y1] != -1 && dx[dir[x1][y1]]+x1==P.x && dy[dir[x1][y1]]+y1==P.y && ans[x1][y1] == 0) {
								ans[x1][y1] = z;
								L.add(new Pair(x1,y1));
							}
						}
					}
					z=(char)(z+1);
				}
			}
			if (ans[0][0] != 'a') System.err.println("kyon kun denwa");
			System.out.printf("Case #%d:\n",ii);
			for (int i = 0; i<H; ++i) {
				for (int j = 0; j<W; ++j) {
					System.out.print(((j==0)?"":" ")+ans[i][j]);
				}
				System.out.println();
			}
		}
	}
	public static boolean valid (int r, int c) {
		return (r >= 0 && c>=0 && r<H && c<W);
	}
	static class Pair { int x,y;public Pair(int xx, int yy){x=xx;y=yy;}}

public static int nextInt() throws Throwable {
		int i = 0;
		boolean negative = false;
		while (i < 44) i = System.in.read();
		if (i == 45) {
			negative = true; i = 0;
		} else {
			 i = i - 48;
		}
		int j = System.in.read();
		while (j > 47) {i*=10;i+=j-48;j = System.in.read();}
		return (negative) ? -i : i;
}

public static String nextLine() throws Throwable {
		StringBuilder b = new StringBuilder(7);
		int j = System.in.read();
		while (j < 32) j = System.in.read();
		while (j != 10) {
			b=b.append((char)j);
			j=System.in.read();
		}
		//System.err.println("Input : " + b);
		return b.toString();
	}}