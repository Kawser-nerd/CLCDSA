import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ", 3);
		int r = Integer.parseInt(arr[0]);
		int c = Integer.parseInt(arr[1]);
		int d = Integer.parseInt(arr[2]);
		int[][] field = new int[r][c];
		for (int i = 0; i < r; i++) {
			String[] line = br.readLine().split(" ", c);
			for (int j = 0; j < c; j++) {
				field[i][j] = Integer.parseInt(line[j]);
			}
		}
		int max = 0;
		for (int i = 0; i < r; i++) {
			for (int j = ((d - i) % 2 == 0) ? 0 : 1; j < c && j <= d - i; j += 2) {
				int x = field[i][j];
				if (max < x) {
					max = x;
				}
			}
		}
		System.out.println(max);
	}
}