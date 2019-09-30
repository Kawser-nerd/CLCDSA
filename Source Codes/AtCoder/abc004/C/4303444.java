import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		N %= 30;
		
		char[] map = {'1','2','3','4','5','6'};
		for (int i = 0; i < N; i++) {
			char a = map[i % 5];
			char b = map[i % 5 + 1];
			map[i % 5] = b;
			map[i % 5 + 1] = a;
		}
		
		System.out.println(new String(map));
	}	
		
}