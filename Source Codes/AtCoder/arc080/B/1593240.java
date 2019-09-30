import java.util.*;

// ARC 80-D
// http://arc080.contest.atcoder.jp/tasks/arc080_b

public class Main {
	
	public static void main (String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		
		int H = in.nextInt();
		int W = in.nextInt();
		int N = in.nextInt();
		
		int[] color = new int[N];
		for (int i = 0; i < N; i++) {
			color[i] = in.nextInt();
		}
		
		int row = 0;
		int col = 0;
		int colorIndex = 0;
		boolean toRight = true;
		
		while (row < H) {
			String s = "";
			if (toRight) {
				while (col < W) {
					if (color[colorIndex] == 0) {
						colorIndex++;
					}
					s += (colorIndex + 1) + " ";
					color[colorIndex]--;
					col++;
				}
				col--;
				toRight = false;
			} else {
				while (0 <= col) {
					if (color[colorIndex] == 0) {
						colorIndex++;
					}
					s = (colorIndex + 1) + " " + s;
					color[colorIndex]--;
					col--;
				}
				col++;
				toRight = true;
			}
			row++;
			System.out.println(s);
		}
	}
}