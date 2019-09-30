import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int a = 1;
		
		for(int i = 2 ; i <= x ; i++) {
			int b = i * i;
			while(b <= x) {
				a = Math.max(a , b);
				b = b * i;
			}
		}
		
		System.out.println(a);
	}

}