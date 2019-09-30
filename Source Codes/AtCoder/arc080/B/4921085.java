import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;


public class Main {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int h = s.nextInt();
		int w = s.nextInt();
		s.nextLine();
		int n = s.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		int x = 0, y = 0;
		int turn = 0;
		int[][] move = {{1, 0}, {-1, 0}};
		int[][] d = new int[h][w];
		
		for (int i = 0; i < n; i++) {
			while (arr[i] != 0) {
				
				arr[i]--;
				d[x][y] = i + 1;
				x += move[turn % 2][0];
				y += move[turn % 2][1];
				if (x < 0 || y < 0 || x == h || y == w) {
					turn++;
					y++;
					x += move[turn % 2][0];
					y += move[turn % 2][1];
				}
				
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if(j==0)
				System.out.print(d[i][j]);
				else System.out.print(" "+d[i][j]);
			}
			System.out.println();
		}
		
		
	}
}