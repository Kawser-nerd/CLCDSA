import java.util.*;

public class Main {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int l = sc.nextInt();
		int idx = 0;
		int prev = sc.nextInt();
		for (int i = 1; i < n; i++) {
			int x = sc.nextInt();
			if (x + prev >= l) {
				idx = i;
				break;
			}
			prev = x;
		}
		if (idx == 0) {
			System.out.println("Impossible");
		} else {
			StringBuilder sb = new StringBuilder();
			sb.append("Possible").append("\n");
			for (int i = 1; i < idx; i++) {
				sb.append(i).append("\n");
			}
			for (int i = n - 1; i > idx; i--) {
				sb.append(i).append("\n");
			}
			sb.append(idx);
			System.out.println(sb);
		}
	}
}