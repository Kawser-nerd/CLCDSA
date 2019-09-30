import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		if(b-a+1 >= k*2) {
            for (int i = a ; i < a + k ; i++) {
                System.out.println(i);
            }
            for (int i = k ; i > 0 ; i--) {
                System.out.println(b - i + 1);
            }
		}else {
			for(int i=a ; i<=b ; i++) {
				System.out.println(i);
			}
		}
	}
}