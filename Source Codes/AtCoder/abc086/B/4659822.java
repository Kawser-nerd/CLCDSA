import java.util.Scanner;


public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		String a = sc.next();
		String b = sc.next();

		sc.close();

		String ab = a + b;
		int value = Integer.parseInt(ab);

		String ans = "No";

		for(int i = 4; i <= Math.sqrt(value); i++){
			if(i*i == value){
				ans = "Yes";
				break;
			}
		}

		System.out.println(ans);
	}
}