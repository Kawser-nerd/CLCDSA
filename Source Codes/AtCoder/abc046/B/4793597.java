import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int k = scan.nextInt();
		int sum = k;

		if(n == 1){
			System.out.println(sum);
			return;
		}


		for(int i = 0; i < n-1; i++){
			sum = sum * (k-1);
		}
		System.out.println(sum);
	}
}