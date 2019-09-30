import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int H = in.nextInt();
		int W = in.nextInt();
		int[][] c = new int[10][10];
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				c[i][j] = in.nextInt();
			}
		}
		
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				for(int k=0;k<10;k++) {
					c[j][k] = Math.min(c[j][k], c[j][i] + c[i][k]);
				}
			}
		}
		
		int ans = 0;
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				int num = in.nextInt();
				if(num>=0) ans += c[num][1];
			}
		}
		System.out.println(ans);
		in.close();

	}

}