//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int h = sc.nextInt(); int w = sc.nextInt();
		char[][] map = new char[h][w];
		for (int i=0; i<h; i++) map[i] = sc.next().toCharArray();
		
		for (int i=0; i<h; i++) {
			boolean F = true;
			for (int j=0; j<w; j++) {
				if (map[i][j] == '#') {
					F = false; break;
				}
			}
			if (F == true) {
				for (int j=0; j<w; j++) {
					map[i][j] = 'x';
				}
			}
		}
		
		for (int i=0; i<w; i++) {
			boolean F = true;
			for (int j=0; j<h; j++) {
				if (map[j][i] == '#') {
					F = false; break;
				}
			}
			if (F == true) {
				for (int j=0; j<h; j++) {
					map[j][i] = 'x';
				}
			}
		}
		
		for (int i=0; i<h; i++) {
			StringBuilder sb = new StringBuilder("");
			boolean F = true;
			for (int j=0; j<w; j++) {
				if (map[i][j] != 'x') sb.append(map[i][j]);
			}
			if (!sb.toString().equals("")) System.out.println(sb);
			
		}
		
	}
}