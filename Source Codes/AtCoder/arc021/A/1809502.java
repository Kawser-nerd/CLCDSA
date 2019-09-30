import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] a = new int[4][4];
		for(int i = 0 ; i < 4 ; i++) {
			for(int j = 0 ; j < 4 ; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		int[] dx = {1, 0, 0, -1};
		int[] dy = {0, 1, -1, 0};
		for(int i = 0 ; i < 4 ; i++) {
			for(int j = 0 ; j < 4 ; j++) {
				for(int k = 0 ; k < 4 ; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(0 <= nx && nx < 4 && 0 <= ny && ny < 4 && a[i][j] == a[nx][ny]) {
						System.out.println("CONTINUE");
						return;
					}
				}
			}
		}
		System.out.println("GAMEOVER");
	}
}