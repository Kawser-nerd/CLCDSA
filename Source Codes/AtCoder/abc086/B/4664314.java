import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int bb = b;
		int count = 0;
		int c  = 0;
		while(bb > 0) {
			bb /= 10;
			count++;
		}
		for(int i = 0; i < count; i++) {
			a = a * 10;
		}
		c = a + b;
		if(Math.sqrt(c) % 1 == 0) {
			System.out.println("Yes");
			return;
		}
		else System.out.println("No");
		sc.close();
	}

}