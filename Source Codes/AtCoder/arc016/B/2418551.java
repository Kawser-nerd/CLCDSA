import java.util.Scanner;

public class Main {

	static int[] dx = {-1, 1};
	static int[] dy = {0, 0};
	static int n;
	static char[][] s;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = new char[n][9];
		for(int i = 0 ; i < n ; i++) s[i] = sc.next().toCharArray();
		int ans = 0;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < 9 ; j++) {
				if(s[i][j] == 'o') {
					ans++;
					dfs(i, j);
				}
				else if(s[i][j] == 'x') {
					ans++;
					s[i][j] = '.';
				}
			}
		}
		System.out.println(ans);
	}

	static void dfs(int x, int y) {
		for(int i = 0 ; i < 2 ; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < 9 && s[nx][ny] == 'o') {
				s[nx][ny] = '.';
				dfs(nx, ny);
			}
		}
		return;
	}

}