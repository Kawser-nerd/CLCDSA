import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(a);
		
		long ans = 1;
		int[] num = new int[n/2];
		int half = 0;
		if(n%2 == 0){
			for(int i=0; i<n; i++){
				if(a[i]%2 == 0){
					System.out.println(0);
					return;
				}
				num[a[i] / 2]++;
			}
		}else{
			for(int i=0; i<n; i++){
				if(a[i]%2 == 1){
					System.out.println(0);
					return;
				}
				if(a[i] == 0){
					half++;
				}else{
					num[a[i] / 2 - 1]++;
				}
			}
			if(half != 1){
				System.out.println(0);
				return;
			}
		}
		for(int i=0; i<n/2; i++){
			if(num[i/2] != 2){
				System.out.println(0);
				return;
			}
			ans *= 2;
			if(ans >= 1000000007){
				ans %= 1000000007;
			}
		}
		System.out.println(ans);

	}

}