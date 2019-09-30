import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		final int[] TABLE = new int[]{-1, 1, 1, 2, -1, 4, 9, 8, -1, 3, 8, 5, 7, 9, -1, 7, 4, 0, 6, 3, -1, 5, 2, 6, -1, 0};
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (count != 0) {
				sb.append(" ");
			}
			String s = sc.next().toLowerCase();
			count = 0;
			for (char c : s.toCharArray()) {
				if (c < 'a' || c > 'z') {
					continue;
				}
				int v = TABLE[c - 'a'];
				if (v == -1) {
					continue;
				}
				sb.append(v);
				count++;
			}
		}
		System.out.println(sb.toString().trim());
	}
}