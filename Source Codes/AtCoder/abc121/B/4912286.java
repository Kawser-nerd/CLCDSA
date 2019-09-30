import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int c = sc.nextInt();
		int[] b = new int[m];
		for(int i=0; i< m; i++)
			b[i] = sc.nextInt();
		
		int count = 0;
		for(int i= 0; i< n; i++) {
			int sum = c;
			for(int j = 0; j <m; j++) 
				sum += sc.nextInt() * b[j];
			if(sum > 0)
				count++;
		}
		System.out.println(count);
		
	}
}