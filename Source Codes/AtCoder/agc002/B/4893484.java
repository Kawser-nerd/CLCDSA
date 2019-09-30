import java.util.*;

public class Main {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] boxes = new int[n];
		boolean[] reds = new boolean[n];
		Arrays.fill(boxes, 1);
		reds[0] = true;
		for (int i = 0; i < m; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			if (boxes[x] == 1 && reds[x]) {
				reds[x] = false;
				reds[y] = true;
			} else if (reds[x]) {
				reds[y] = true;
			}
			boxes[x]--;
			boxes[y]++;
		}
		int count = 0;
		for (boolean b : reds) {
			if (b) {
				count++;
			}
		}
		System.out.println(count);
	}
}