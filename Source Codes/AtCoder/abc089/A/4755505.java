import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N>3) {
			System.out.println(N/3);
		}else {
			System.out.println(0);
		}
		sc.close();
	}

}