import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] pow = new int[n];
		int total = 0;
		int amari =0;
		int ans = 0;

			for(int i=0; i<n; i++) {
				pow[i]=sc.nextInt();
				total+=pow[i];
			}
			Arrays.sort(pow);
			amari = x-total;
				if(amari == 0) {
					ans =n;
				}else {
					ans=(amari/pow[0])+n;
				}
		System.out.println(ans);
	}

}