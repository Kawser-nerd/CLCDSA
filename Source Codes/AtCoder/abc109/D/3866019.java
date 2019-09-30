import java.util.*;

public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int[][] place = new int[w][h];
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				place[i][j] = sc.nextInt();
			}
		}
		int i = 0; 
		int j = 0;
		int ni = 0;
		int nj = 0;
		int count = 0;
		StringBuilder sb = new StringBuilder();
		while (true) {
			if (j % 2 == 0) {
				if (i == w - 1) {
					ni = i;
					nj = j + 1;
					if (nj == h) {
						break;
					}
				} else {
					ni = i + 1;
					nj = j;
				}
			} else {
				if (i == 0) {
					ni = i;
					nj = j + 1;
					if (nj == h) {
						break;
					}
				} else {
					ni = i - 1;
					nj = j;
				}
			}
			if (place[i][j] % 2 != 0) {
				sb.append(j + 1).append(" ").append(i + 1).append(" ").append(nj + 1).append(" ").append(ni + 1).append("\n");
				place[i][j] -= 1;
				place[ni][nj] += 1;
				count++;
			}
			i = ni;
			j = nj;
		}
		System.out.println(count);
		System.out.print(sb);
	}
	
}