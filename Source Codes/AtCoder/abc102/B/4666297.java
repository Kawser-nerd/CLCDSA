import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max = 0, min = 1000000000;
		int n = sc.nextInt();
		int a = 0;
		for(int i = 0; i < n; i++) {
			a = sc.nextInt();
			if(max < a) {
				max = a;
			}
			if(a < min) {
				min = a;
			}
		}
		System.out.println(max - min);
		sc.close();
	}

}