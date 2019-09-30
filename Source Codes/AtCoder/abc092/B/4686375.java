import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D = sc.nextInt();
		int X = sc.nextInt();
		
		int[] data = new int[N];
		
		for(int i = 0; i < N; i++) {
			data[i] = sc.nextInt();
		}
		
		int cnt = 0;
		
		for(int i = 0; i < N; i++) {
			int x = 1;
			while(x <= D) {
				cnt++;
				x += data[i];
			}
		}
		
		System.out.println(X + cnt);
		
		sc.close();

	}

}