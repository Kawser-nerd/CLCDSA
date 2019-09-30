import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] pArray = new int [n];
		int pmax = 0, sum = 0;
		for(int i = 0; i < n; i++) {
			pArray[i] = sc.nextInt();
			sum = sum + pArray[i];
			if(pmax <= pArray[i]) pmax = pArray[i];
		}
		System.out.println(sum - (pmax / 2));
		sc.close();
	}
}