import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int R = Integer.parseInt(sc.next());
		int C = Integer.parseInt(sc.next());
		int K = Integer.parseInt(sc.next());
		String s[] = new String[R];
		String color[][] = new String[R][C];
		for(int i = 0; i < R; i++) {
			s[i] = sc.next();
			for(int j = 0; j < C; j++) {
				color[i][j] = s[i].substring(j, j + 1);
			}
		}
		
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(i < K - 1 || i > R - K || j < K - 1 || j > C - K) {
					if(color[i][j].equals("o")) {
						color[i][j] = "*";
					}
				}
				//System.out.println(color[i][j]);
				if(color[i][j].equals("x")) {
					for(int y = i - (K - 1); y <= i + (K - 1); y++) {
						if(y < 0 || y >= R) continue;
						int width = (K - 1) - Math.abs(y - i);
						for(int x = j - width; x <= j + width; x++) {
							if(x < 0 || x >= C) continue;
							if(color[y][x].equals("o")) {
								color[y][x] = "*";
							}
						}
					}
				}
			}
		}
		
		int ans = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(color[i][j].equals("o")) ans++;
			}
		}
		System.out.println(ans);
	}
}