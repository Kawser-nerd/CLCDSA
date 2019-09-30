import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		String s = sc.next();
		String[] field = new String[9];
		int count = 0;
		for (int i = 0; i < 9; i++) {
			field[i] = sc.next();
		}
		int dx = 0;
		int dy = 0;
		if (s.equals("R")) { //: ???
			dx = 1;
			dy = 0;
		} else if (s.equals("L")) { // : ???
			dx = -1;
			dy = 0;
		} else if (s.equals("U")) { // : ???
			dx = 0;
			dy = -1;
		} else if (s.equals("D")) { // : ???
			dx = 0;
			dy = 1;
		} else if (s.equals("RU")) { // : ???????
			dx = 1;
			dy = -1;
		} else if (s.equals("RD")) { // : ???????
			dx = 1;
			dy = 1;
		} else if (s.equals("LU")) { // : ???????
			dx = -1;
			dy = -1;
		} else if (s.equals("LD")) { // : ???????
			dx = -1;
			dy = 1;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			sb.append(field[y - 1].charAt(x - 1));
			if (x == 1 && dx == -1) {
				dx = 1;
			}
			if (x == 9 && dx == 1) {
				dx = -1;
			}
			if (y == 1 && dy == -1) {
				dy = 1;
			}
			if (y == 9 && dy == 1) {
				dy = -1;
			}
			x += dx;
			y += dy;
		}
		System.out.println(sb);
	}
}