import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] map = new int[N];
		for (int i = 0; i < M; i++) {
			map[sc.nextInt()-1]++;
			map[sc.nextInt()-1]++;
		}
		
		for (int i = 0; i < N; i++) {
			System.out.println(map[i]);
		}
	}
	
	
}