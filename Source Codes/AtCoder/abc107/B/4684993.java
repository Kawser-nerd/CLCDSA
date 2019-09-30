import java.util.Scanner;
import java.util.Arrays;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt(), w = sc.nextInt();
		String [][] a = new String [h][w];
		boolean [] hjudge = new boolean [h];
		boolean [] wjudge = new boolean [w];
		Arrays.fill(hjudge, false);
		Arrays.fill(wjudge, false);
		for(int i = 0; i < h; i++) {
			String x = sc.next();//??a??
			a[i] = x.split("");
		}

		for(int i = 0; i < h; i++) {//hjudge
			for(int k = 0; k < w; k++) {
				if(a[i][k].equals("#")) hjudge[i] = true;
			}
		}

		for(int i = 0; i < w; i++) {//wjudge
			for(int k = 0; k < h; k++) {
				if(a[k][i].equals("#")) wjudge[i] = true;
			}
		}

		for(int i = 0; i < h; i++) {//??
			if(hjudge[i]) {
				for(int k = 0; k < w; k++) {
					if(wjudge[k]) System.out.print(a[i][k]);
				}
				System.out.println();
			}
		}

		sc.close();
	}
}