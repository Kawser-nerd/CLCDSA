import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] lArray = new int [n];
		int sum = 0, lon = 0;
		for(int i = 0; i < n; i++) {
			lArray[i] = sc.nextInt();
			sum = sum + lArray[i];
			if(lon <= lArray[i]) lon = lArray[i];
		}
		if(lon < (sum - lon)) System.out.println("Yes");
		else System.out.println("No");
		sc.close();
	}

}