import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] t = new int[n];
		for(int i = 0; i < n; i++){
			t[i] = scan.nextInt();
		}
		int m = scan.nextInt();
		int[] p = new int[m];
		int[] x = new int[m];
		for(int i = 0; i < m; i++){
			p[i] = scan.nextInt();
			x[i] = scan.nextInt();
		}

		for(int i = 0; i < m; i++){
			int s = t[p[i]-1];
			t[p[i]-1] = x[i];
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += t[j];
			}
			System.out.println(sum);
			t[p[i]-1] = s;
		}
	}
}