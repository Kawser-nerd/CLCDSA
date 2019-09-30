import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		char[] s = sc.next().toCharArray();
		
		int N = sc.nextInt();
		int[][] map = new int[N][2];
		for (int i = 0; i < N; i++) {
			map[i][0] = sc.nextInt();
			map[i][1] = sc.nextInt();
		}
		
		for (int i = 0; i < N; i++) {
			int start = map[i][0];
			int end = map[i][1];
			
			String tmp = new String(s);
			char[] target = tmp.substring(start-1, end).toCharArray();
			
			for (int j = 0; j <= end-start; j++) {
				s[start-1+j] = target[target.length-j-1];
			}
		}
		
		System.out.println(new String(s));
	}
	
}