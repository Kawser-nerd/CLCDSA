import java.util.Scanner;
//??????????????Mian???
public class Main{
	public static void main(String[] args){

		int n;
		int ng1;
		int ng2;
		int ng3;
		String ans;

		try(Scanner scan = new Scanner(System.in);){

			n = scan.nextInt();
			ng1 = scan.nextInt();
			ng2 = scan.nextInt();
			ng3 = scan.nextInt();

		}

		if(n == ng1 || n == ng2 || n == ng3) {
			ans = "NO";
		}else {

			for(int i = 0; i < 100; i++ ) {

				if(n - 3 != ng1 && n - 3 != ng2 && n - 3 != ng3) {
					n -= 3;
				}else if(n - 2 != ng1 && n - 2 != ng2 && n - 2 != ng3) {
					n -= 2;
				}else if(n - 1 != ng1 && n - 1 != ng2 && n - 1 != ng3) {
					n -= 1;
				}else{
					ans = "NO";
					break;
				}

			}

			if(n > 0) {
				ans = "NO";
			}else {
				ans = "YES";
			}
		}

		System.out.println(ans);

	}

}