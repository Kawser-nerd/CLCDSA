import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);     
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		for(int i = a;i < a + k;i++) {
			if(i <= b) System.out.println(i);
		}
		for(int i = b - k + 1;i <= b;i++) {
			if(i >= a + k && i >= a) System.out.println(i);
		}
        sc.close();
	}

}