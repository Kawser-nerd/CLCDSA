import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int h = sc.nextInt();
		int m = sc.nextInt();
		int ans = 0;

		if(h < 17) {
			if(m == 0) {
				ans = (18-h)*60;
			}else {
				ans = ((17-h)*60)+(60-m);
			}
		}else {
			ans = 60-m;
		}
		System.out.println(ans);
	}

}