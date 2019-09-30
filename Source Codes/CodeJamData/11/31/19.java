import java.util.Scanner;


public class Problem {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			char[][] map = new char[55][55];
			int R = sc.nextInt();
			int C = sc.nextInt();
			for (int j = 1; j <= R; j++) {
				String line = sc.next();
				for (int k = 1; k <= C; k++) {
					map[j][k] = line.charAt(k - 1);
				}
			}
			
			boolean possible = true;
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					if (map[j][k] == '#') {
						map[j][k] = '/';
						if (map[j][k+1] =='#' && map[j+1][k+1]=='#' && map[j+1][k+1]=='#') {
							map[j][k+1] = '\\';
							map[j+1][k] = '\\';
							map[j+1][k+1] = '/';
						} else {
							possible = false;
						}
					}
				}
			}
			
			if (!possible) {
				System.out.format("Case #%d:\n", i);
				System.out.println("Impossible");
			} else {
				System.out.format("Case #%d:\n", i);
				for (int j = 1; j <= R; j++) {
					for (int k = 1; k <= C; k++) {
						System.out.print(map[j][k]);
					}
					System.out.println();
				}
			}
		}
	}
	
}
