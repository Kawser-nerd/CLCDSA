import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();int m = sc.nextInt();
		int[] arr = new int[m];
		boolean[] table = new boolean[n];
		for(int i = 0; i < m; i++) {
			arr[m-1-i] = sc.nextInt()-1;
		}
		for(int i = 0; i < m; i++) {
			int a = arr[i];
			if(table[a]==false) {
				table[a] = true;
				System.out.println(a+1);
			}
		}
		for(int i = 0; i < n; i++) {
			if(table[i]==false) {
				table[i] = true;
				System.out.println(i+1);
			}
		}
	}
}