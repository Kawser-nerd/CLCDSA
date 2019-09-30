import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int k = sc.nextInt();
		Area[] areas = new Area[d];
		for (int i = 0; i < d; i++) {
			areas[i] = new Area(sc.nextInt(), sc.nextInt());
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < k; i++) {
			int s = sc.nextInt();
			int t = sc.nextInt();
			int now = s;
			boolean up = t > s;
			for (int j = 0; j < d; j++) {
				if (areas[j].left <= now && areas[j].right >= now) {
					if (areas[j].left <= t && areas[j].right >= t) {
						sb.append(j + 1).append("\n");
						break;
					}
					if (up) {
						if (now < areas[j].right) {
							now = areas[j].right;
						}
					} else {
						if (now > areas[j].left) {
							now = areas[j].left;
						}
					}
				}
			}
		}
		System.out.print(sb);
	}
	
	static class Area {
		int left;
		int right;
		public Area(int left, int right) {
			this.left = left;
			this.right = right;
		}
	}
}