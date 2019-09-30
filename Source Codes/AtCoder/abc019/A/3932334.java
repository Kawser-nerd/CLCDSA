import java.util.Arrays;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] map = new int[3];
		for (int i = 0; i < 3; i++) {
			map[i] = sc.nextInt();
		}
		
		Arrays.sort(map);
		
		System.out.println(map[1]);
	}
}