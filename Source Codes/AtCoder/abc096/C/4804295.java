import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] s = new int[H+2][W+2];
		boolean able = true;
		for(int i = 1; i <= H; i++){
			String scan = sc.next();
			for(int j = 1; j <= W; j++){
				if(scan.charAt(j-1) == '#')
					s[i][j] = 1;
				else
					s[i][j] = 0;
			}
		}
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(s[i][j] == 1){
					if(s[i-1][j] == 0 && s[i+1][j] == 0 && s[i][j-1] == 0 && s[i][j+1] == 0)
						able = false;
				}
			}
		}
		System.out.println(able ? "Yes":"No");
	}

}