import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cnt = 0;
		if(n/100 == 1) cnt++;
		if(n/10%10 == 1) cnt++;
		if(n%10 == 1) cnt++;
		System.out.println(cnt);
	}
}