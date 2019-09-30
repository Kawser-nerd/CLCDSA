import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] peoples = new int[n];
		int from = 0;
		int to = 0;


		for(int i=0; i<n; i++) {
			from += 0;
			to += 0;
			from = sc.nextInt();
			to = sc.nextInt();
			peoples[i] = (to-from+1);
		}
		int total = 0;
			for(int j=0; j<peoples.length; j++) {
				total += peoples[j];
			}
		System.out.println(total);

	}

}