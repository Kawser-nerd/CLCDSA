import java.io.File;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Map.Entry;

public class Main {
	
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int C = in.nextInt();
		int[][] D = new int[C][C];
		long[][] d = new long[3][C];
		
		for(int i = 0; i < C; i++){
			for(int j = 0; j < C; j++) D[i][j] = in.nextInt();
		}
		
		int[][] c = new int[N][N];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				c[i][j] = in.nextInt();
				for(int k = 1; k <= C; k++){
					d[((i + j) % 3)][k-1] += D[c[i][j]-1][k-1];
				}
			}
		}
		
		long min = Long.MAX_VALUE;
		for(int i = 1; i <= C; i++){
			for(int j = 1; j <= C; j++){
				if(i == j) continue;
				for(int k = 1; k <= C; k++){
					if(i == k || j == k) continue;
					long cost = 0;
					cost += d[0][i-1];
					cost += d[1][j-1];
					cost += d[2][k-1];
					min = Math.min(min, cost);
				}
			}
		}
		
		System.out.println(min);
	}
}