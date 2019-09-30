import java.util.*;
public class Main {
	static int place[][] = new int[8][8];
	static boolean putCount[][] = new boolean[8][8];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < 8; i ++) {
			String tmp = sc.next();
			for(int j = 0; j < 8; j ++) {
				if(tmp.charAt(j) == 'Q') {
					plus(i, j, true);
					putCount[i][j] = true;
				}
			}
		}
		if(check(5)) {
			boolean ok = true;
			for(int i = 0; i < 8; i ++) {
				for(int j = 0; j < 8; j ++) {
					if(putCount[i][j] && place[i][j] > 0) {
						ok = false;
					}
				}
			}
			if(ok) {
				for(int i = 0; i < 8; i ++) {
					for(int j = 0; j < 8; j ++) {
						System.out.print(putCount[i][j] ? "Q" : ".");
					}
					System.out.println();
				}
			}else {
				System.out.println("No Answer");
			}
		}else {
			System.out.println("No Answer");
		}
	}
	public static boolean check(int putNum) {
		for(int i = 0; i < 8; i ++) {
			for(int j = 0; j < 8; j ++) {
				if(place[i][j] == 0 && !putCount[i][j]) {
					plus(i, j, true);
					putCount[i][j] = true;
					if(putNum == 1) {
						return true;
					}
					if(check(putNum - 1)) {
						return true;
					}else {
						plus(i, j, false);
						putCount[i][j] = false;
					}
				}
			}
		}
		return false;
	}
	public static void plus(int row, int column, boolean plus) {
		for(int i = 0; i < 8; i ++) {
			place[row][i] += plus ? 1 : -1;
		}
		for(int i = 0; i < 8; i ++) {
			place[i][column] += plus ? 1 : -1;
		}
		int firstR = Math.min(row + column, 7);
		int firstC = Math.max(row + column - 7, 0);
		for(int i = 0; (firstR - i) >= 0 && (firstC + i) < 8; i ++) {
			place[firstR - i][firstC + i] += plus ? 1 : -1;
		}
		firstR = Math.max(row - column, 0);
		firstC = Math.max(column - row, 0);
		for(int i = 0; (firstR + i) < 8 && (firstC + i) < 8; i ++) {
			place[firstR + i][firstC + i] += plus ? 1 : -1;
		}
		place[row][column]  -= 4 * (plus ? 1 : -1);
	}
}