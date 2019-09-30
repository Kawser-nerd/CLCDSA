import java.util.*;

public class DSmall {
	static final int P = 10007;
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int N = sc.nextInt();
		for(int caseID = 1; caseID <= N; caseID++){
			int H = sc.nextInt();
			int W = sc.nextInt();
			int R = sc.nextInt();
			boolean[][] rock = new boolean[H][W];
			for(int i = 0; i < R; i++){
				int r = sc.nextInt() - 1;
				int c = sc.nextInt() - 1;
				rock[r][c] = true;
			}
			int[][] count = new int[H + 2][W + 2];
			count[0][0] = 1;
			for(int y = 0; y < H; y++){
				for(int x = 0; x < W; x++){
					if(rock[y][x]) continue;
					count[y + 2][x + 1] += count[y][x];
					count[y + 2][x + 1] %= P;
					count[y + 1][x + 2] += count[y][x];
					count[y + 1][x + 2] %= P;
				}
			}
			System.out.printf("Case #%d: %d%n", caseID, count[H - 1][W - 1]);
		}
	}
}
