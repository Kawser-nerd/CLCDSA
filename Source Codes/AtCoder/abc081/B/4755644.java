import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int min = 1000000000;
		
		for(int i = 0 ; i < n ; i++) {
			int a = sc.nextInt();
			int count = 0;
			
			while(a % 2 == 0) {
				a = a / 2;
				count++;
			}
			
			min = Math.min(min , count);
		}
		
		System.out.println(min);
	}
}