import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] s = new int[H+2][W+2];
		boolean able = true;
		for(int i = 1; i <= H; i++){
			String st = sc.next();
			for(int j = 1; j <= W; j++){
				s[i][j] = st.charAt(j-1);
			}
		}
		for(int i = 1; i < H; i++){
			for(int j = 1; j < W; j++){
				if(s[i][j] == '#' && s[i-1][j] != '#' && s[i+1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#')
						able = false;
			}
		}
		System.out.println(able ? "Yes":"No");
	}

}