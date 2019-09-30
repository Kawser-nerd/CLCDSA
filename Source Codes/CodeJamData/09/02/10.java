package gcj2009.qual;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	static final int INF = 1 << 20;
	static final int[] di = { -1, 0, 0, 1 };
	static final int[] dj = { 0, -1, 1, 0 };
	static final int sink = 4;
	
	public void run() {
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] map = new int[H][W];
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				map[i][j] = sc.nextInt();
		int[][] flow = new int[H][W];
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++) {
				int min = map[i][j];
				flow[i][j] = 4;
				for(int d = 0; d < 4; d++)
					if(i + di[d] >= 0 && j + dj[d] >= 0 && i + di[d] < H && j + dj[d] < W)
						if(map[i+di[d]][j+dj[d]] < min) {
							min = map[i+di[d]][j+dj[d]];
							flow[i][j] = d;
						}
			}
		char[][] ans = new char[H][W];
		char c = 'a';
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				if(draw(flow, ans, i, j, c) == c)
					c++;
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < H; i++) {
			sb.append("\n");
			for(int j = 0; j < W; j++)
				sb.append(ans[i][j] + " ");
		}
		System.out.println(sb);
	}
	
	char draw(int[][] flow, char[][] ans, int i, int j, char c) {
		if(ans[i][j] == 0)
			if(flow[i][j] == 4)
				return ans[i][j] = c;
			else
				return ans[i][j] = draw(flow, ans, i + di[flow[i][j]], j + dj[flow[i][j]], c);
		else
			return ans[i][j];
	}
	
	public static void main(String...args) {
		try { 
			System.setIn(new FileInputStream("B-large.in"));
			System.setOut(new PrintStream("B-large.out"));
		} catch(Exception e) {}
		sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			System.out.printf("Case #%d: ", t);
			new B().run();
		}
	}
	
	static Scanner sc;
}
