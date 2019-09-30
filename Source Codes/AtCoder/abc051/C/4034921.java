import java.util.*;
import java.lang.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sx = sc.nextInt();
		int sy = sc.nextInt();
		int tx = sc.nextInt();
		int ty = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		if (sx < tx && sy < ty) {
			for (int i = 0; i < tx - sx; i++) {
				sb.append('R');
			}
			for (int i = 0; i < ty - sy; i++) {
				sb.append('U');
			}
			for (int i = 0; i < tx - sx; i++) {
				sb.append('L');
			}
			for (int i = 0; i < ty - sy; i++) {
				sb.append('D');
			}
			sb.append('D');
			for (int i = 0; i < tx - sx + 1; i++) {
				sb.append('R');
			}
			for (int i = 0; i < ty - sy + 1; i++) {
				sb.append('U');
			}
			sb.append('L');
			sb.append('U');
			for (int i = 0; i < tx - sx + 1; i++) {
				sb.append('L');
			}
			for (int i = 0; i < ty - sy + 1; i++) {
				sb.append('D');
			}
			sb.append('R');
		} else if (sx < tx && sy > ty) {
			for (int i = 0; i < tx - sx; i++) {
				sb.append('R');
			}
			for (int i = 0; i < sy - ty; i++) {
				sb.append('D');
			}
			for (int i = 0; i < tx - sx; i++) {
				sb.append('L');
			}
			for (int i = 0; i < sy - ty; i++) {
				sb.append('U');
			}
			sb.append('U');
			for (int i = 0; i < tx - sx + 1; i++) {
				sb.append('R');
			}
			for (int i = 0; i < sy - ty + 1; i++) {
				sb.append('D');
			}
			sb.append('L');
			sb.append('D');
			for (int i = 0; i < tx - sx + 1; i++) {
				sb.append('L');
			}
			for (int i = 0; i < sy - ty + 1; i++) {
				sb.append('U');
			}
			sb.append('R');
		} else if (sx > tx && sy < ty) {
			for (int i = 0; i < sx - tx; i++) {
				sb.append('L');
			}
			for (int i = 0; i < ty - sy; i++) {
				sb.append('U');
			}
			for (int i = 0; i < sx - tx; i++) {
				sb.append('R');
			}
			for (int i = 0; i < ty - sy; i++) {
				sb.append('D');
			}
			sb.append('D');
			for (int i = 0; i < sx - tx + 1; i++) {
				sb.append('L');
			}
			for (int i = 0; i < ty - sy + 1; i++) {
				sb.append('U');
			}
			sb.append('R');
			sb.append('U');
			for (int i = 0; i < sx - tx + 1; i++) {
				sb.append('R');
			}
			for (int i = 0; i < ty - sy + 1; i++) {
				sb.append('D');
			}
			sb.append('L');
		} else {
			for (int i = 0; i < sx - tx; i++) {
				sb.append('L');
			}
			for (int i = 0; i < sy - ty; i++) {
				sb.append('D');
			}
			for (int i = 0; i < sx - tx; i++) {
				sb.append('R');
			}
			for (int i = 0; i < sy - ty; i++) {
				sb.append('U');
			}
			sb.append('U');
			for (int i = 0; i < sx - tx + 1; i++) {
				sb.append('L');
			}
			for (int i = 0; i < sy - ty + 1; i++) {
				sb.append('D');
			}
			sb.append('R');
			sb.append('D');
			for (int i = 0; i < sx - tx + 1; i++) {
				sb.append('R');
			}
			for (int i = 0; i < sy - ty + 1; i++) {
				sb.append('U');
			}
			sb.append('L');
		}
		System.out.println(sb);
	}
}