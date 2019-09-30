import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int initialN = n;
		int x = 0;
		while(n % 10 != 0) {
			x += n % 10;
			n /= 10;
		}
		if(initialN % x == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
		
		
	}
}