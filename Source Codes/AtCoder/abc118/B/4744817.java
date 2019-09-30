import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [] mArray = new int [m+1];
		for(int i = 0; i < n; i++) {
			int k = sc.nextInt();
			int [] aArray = new int [k];
			for(int j = 0; j < k; j++) {
				aArray[j] = sc.nextInt();
				mArray[aArray[j]]++;
			}
		}
		int result = 0;
		for(int i = 1; i < m+1; i++) {
			if(mArray[i] == n) result++;
		}
		System.out.println(result);
		sc.close();
	}

}