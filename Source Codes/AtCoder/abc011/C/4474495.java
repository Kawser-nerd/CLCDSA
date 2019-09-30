import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int n = scn.nextInt();
		int ng1 = scn.nextInt();
		int ng2 = scn.nextInt();
		int ng3 = scn.nextInt();

		String ans = "";

		if(n==ng1 || n==ng2 || n==ng3) {
			ans="NO";
		}else {
			for(int i=0; i<100; i++){
				if(n-3 != ng1 && n-3!=ng2 && n-3!=ng3)
					n  -= 3;
				else if(n-2 != ng1 && n-2 !=ng2 && n-2!=ng3)
					n -= 2;
				else if(n-1 != ng1 && n-1 !=ng2 && n-1!=ng3)
				    n -= 1;
			}
			if(n>0)
				ans = "NO";
			else
				ans = "YES";
		}

		System.out.println(ans);
	}
}