//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int h = sc.nextInt(); int w = sc.nextInt();
		char[][] map = new char[h][w];
		for (int i=0; i<h; i++) map[i] = sc.next().toCharArray();
		
		HashSet<Integer> gyo = new HashSet<>();
		HashSet<Integer> retsu = new HashSet<>();
		
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				if (map[i][j] == '#') {
					gyo.add(i); break;
				}
			}
		}
		
		for (int i=0; i<w; i++) {
			for (int j=0; j<h; j++) {
				if (map[j][i] == '#') {
					retsu.add(i); break;
				}
			}
		}
		
		for (int i=0; i<h; i++) {
			boolean F = false;
			for (int j=0; j<w; j++) {
				if (gyo.contains(i) && retsu.contains(j)) {
					System.out.print(map[i][j]);
					F = true;
				}
			}
			if (F == true) System.out.println();
		}
		
	}
}