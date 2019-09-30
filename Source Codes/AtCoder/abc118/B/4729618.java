import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] table = new int[m];
		
		for(int i = 0; i < n; i++) {
			int k = sc.nextInt();
			for(int j = 0; j < k; j++) {
				int a = sc.nextInt();
				table[a-1]++;
			}
		}
		
		int count = 0;
		for(int i = 0; i < m; i++) {
			if(table[i] == n) {
				count++;
			}
		}
		
		System.out.println(count);
		sc.close();
	}
}