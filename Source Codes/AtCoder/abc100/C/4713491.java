import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int count = 0;
		
		for(int i = 0; i < n; i++) {
			long l = Long.parseLong(sc.next());
			while(l % 2 == 0) {
				l /= 2;
				count++;
			}
		}
		
		System.out.println(count);
	}
}