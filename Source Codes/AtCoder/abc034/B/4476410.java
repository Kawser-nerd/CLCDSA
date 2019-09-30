import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);

		int num = scn.nextInt();
		int ans = 0;
		if(num%2 ==0) {
			ans = num-1;
		}else {
			ans = num +1;
		}
		System.out.println(ans);
	}

}