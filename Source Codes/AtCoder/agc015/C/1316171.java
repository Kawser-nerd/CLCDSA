import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int Q = sc.nextInt();
		boolean[][] m = new boolean[N][M];
		for(int i=0; i<N; i++) {
			char[] s = sc.next().toCharArray();
			for(int j=0; j<M; j++)
				m[i][j] = s[j]=='1';
		}
		short[][] hc = new short[N+1][M+1];
		short[][] vc = new short[N+1][M+1];
		int[][] t = new int[N+1][M+1];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				short hd = (short)((i>0 && m[i-1][j] && m[i][j]) ? 1 : 0);
				short vd = (short)((j>0 && m[i][j-1] && m[i][j]) ? 1 : 0);
				hc[i][j+1] = (short)(hc[i][j] + hd);
				vc[i+1][j] = (short)(vc[i][j] + vd);
				t[i+1][j+1] = t[i][j+1] + t[i+1][j] - t[i][j] + (m[i][j] ? 1 : 0) - hd - vd;
			}
		}
		
		for(int i=0; i<Q; i++) {
			int x1 = sc.nextInt()-1;
			int y1 = sc.nextInt()-1;
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			int ans = t[x2][y2]-t[x1][y2]-t[x2][y1]+t[x1][y1] + vc[x2][y1]-vc[x1][y1] + hc[x1][y2]-hc[x1][y1];
			pw.println(ans);
		}
		
		sc.close();
		pw.close();
	}
}