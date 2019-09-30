import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] disks = new int[n];
		for (int i = 0; i < n; i++) {
			disks[i] = i + 1;
		}
		int now = 0;
		for (int i = 0; i < m; i++) {
			int x = sc.nextInt();
			if (x == now) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (disks[j] == x) {
					disks[j] = now;
					now = x;
					break;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(disks[i]).append("\n");
		}
		System.out.print(sb);
	}
}