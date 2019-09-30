import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = 0;
		
		for(int i = a; i <= b ; i++) {
			int d = i % 10;
			int e = i / 10000 % 10;
			int f = i / 10 % 10;
			int g = i / 1000 % 10;
			
			if(d == e && f == g) {
				c++;
			}
		}
		
		System.out.println(c);
		
	}

}