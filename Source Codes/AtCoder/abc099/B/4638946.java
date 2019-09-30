import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);  
		int a = sc.nextInt();
		int b = sc.nextInt();
		int sum = 0;
		for(int i = 1;i < (b - a);i++) {
			sum += i;
		}
		System.out.println(sum - a);
		sc.close();
	}

}