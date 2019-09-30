import java.util.*;
public class C {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			int R = sc.nextInt();
			int [][] G = new int [101][101];
			for (int i =0; i<R; ++i) {
				int X1 = sc.nextInt();
				int Y1 = sc.nextInt();
				int X2 = sc.nextInt();
				int Y2 = sc.nextInt();
				for (int y = Y1; y<=Y2; ++y)
					for (int x = X1; x<=X2; ++x) G[y][x] = 1;
			}
			boolean changed = true;
			int cnt = 0;
			while (changed) {
				changed = false;
				int [][] G2 = new int[101][101];
				for (int j = 1; j<G.length; ++j) G2[0][j] = (G[0][j-1] == 1 && G[0][j] == 1) ? 1 : 0;
				for (int i = 1; i<G.length; ++i) {
					G2[i][0] = (G[i-1][0] == 1 && G[i][0] == 1) ? 1 : 0;
					for (int j = 1; j<G.length; ++j) {
						G2[i][j] = G[i][j];
						if (G[i-1][j] == 1 && G[i][j-1] == 1) G2[i][j] = 1;
						if (G[i-1][j] == 0 && G[i][j-1] == 0) G2[i][j] = 0;
					}
				}
				for (int i = 0; i<G.length; ++i) for (int j = 0; j<G.length; ++j) if (G2[i][j] != G[i][j]) changed=true;
				G = G2;
				cnt++;
			}
			
			System.out.printf("Case #%d: %s\n",ii,(cnt-1)+"");
		}
	}
	
}