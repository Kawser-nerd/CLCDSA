import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int result = 0;
		for(int i = 1; i <= n; i++) {
			int index = i;
			int sum = 0;
			while(index != 0) {
				sum += index % 10;
				index /= 10; 
			}
			if(sum >= a && sum <= b) {
				result += i;
			}
		}
		System.out.println(result);
		
		

		
	}
}