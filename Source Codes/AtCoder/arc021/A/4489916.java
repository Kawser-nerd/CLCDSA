import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = 4;
		int[][]tile = new int[n][n];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)tile[i][j]=Integer.parseInt(sc.next());
		sc.close();
		String res = "GAMEOVER";

		for(int i=0;i<n;i++) {
			int t=tile[i][0];
			for(int j=1;j<n;j++) {
				if(t == tile[i][j]) res = "CONTINUE";
				else t=tile[i][j];
			}
		}
		for(int i=0;i<n;i++) {
			int t=tile[0][i];
			for(int j=1;j<n;j++) {
				if(t == tile[j][i]) res = "CONTINUE";
				else t=tile[j][i];
			}
		}
		System.out.println(res);
	}

}