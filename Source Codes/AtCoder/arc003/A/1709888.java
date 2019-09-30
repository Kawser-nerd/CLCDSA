import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner	sc = new Scanner(System.in);
		int n = sc.nextInt();
		String r = sc.next();
		double total = 0;
		for(int i = 0 ; i < n ; i++) {
			if(r.charAt(i) == 'A') total += 4;
			else if(r.charAt(i) == 'B') total += 3;
			else if(r.charAt(i) == 'C') total += 2;
			else if(r.charAt(i) == 'D') total += 1;
		}
		System.out.printf("%.14f\n", total / n);
	}
}