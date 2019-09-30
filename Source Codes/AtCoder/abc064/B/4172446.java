import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();	
        
        int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		
		Arrays.sort(map);
		
		System.out.println(map[map.length-1] - map[0]);
    }
}