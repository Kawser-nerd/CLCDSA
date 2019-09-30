import java.util.Arrays;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] map = new int[3];
		int[] map2 = new int[3];
		for (int i = 0; i < 3; i++) {
			map[i] = sc.nextInt();
			map2[i] = map[i];
		}
		
		Arrays.sort(map2);
		//swap
		int tmp = map2[0];
		map2[0] = map2[2];
		map2[2] = tmp;
		
		for (int point : map) {
			for (int i = 1; i <= 3; i++) {
				if (point == map2[i-1]) {
					System.out.println(i);
				}
			}
		}
	}
}