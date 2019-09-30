import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] c = new int[3][3];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) 
				c[i][j] = sc.nextInt();
		}
		boolean ok = true;
		for(int i = 1; i <= 2; i++) {
			if(c[0][i] - c[0][i-1] != c[1][i] - c[1][i-1] || c[0][i] - c[0][i-1] != c[2][i] - c[2][i-1])
				ok = false;
		}
		for(int i = 1; i <= 2; i++) {
			if(c[i][0] - c[i-1][0] != c[i][1] - c[i-1][1] || c[i][0] - c[i-1][0] != c[i][2] - c[i-1][2])
				ok = false;
		}
		System.out.println(ok ? "Yes" : "No");
	}

}