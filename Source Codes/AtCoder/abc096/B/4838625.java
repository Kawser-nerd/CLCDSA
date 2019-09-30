import java.util.*;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int [] a = new int[3];
		int ind = 0;
		int max = 0;
		int sum = 0;
		for(int i = 0; i < 3; i++) {
			a[i] = sc.nextInt();
			if(a[i] > max) {
				max = a[i];
				ind = i;
			}
		}
		int k = sc.nextInt();
		for(int i = 0; i < k; i++) {
			a[ind] += a[ind];
		}
		for(int i = 0; i < 3; i++) {
			sum += a[i];
		}
		System.out.println(sum);
		sc.close();
	}

}