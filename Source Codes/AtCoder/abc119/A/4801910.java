import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();

		int ans = Integer.parseInt(S.replace("/", ""));

		if(ans <= 20190430){
			System.out.println("Heisei");
		}
		else{
			System.out.println("TBD");
		}
	}

}