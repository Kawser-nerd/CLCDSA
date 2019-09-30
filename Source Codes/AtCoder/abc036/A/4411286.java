import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		double a = scan.nextInt();
		double b = Integer.parseInt(scan.next());
		double box = b/a;
		double calc = b%a;
		int result = 0;
		if(calc == 0) {
			result = (int)box;
			System.out.println(result);
		}else {
			box=Math.ceil(box);
			result=(int)box;
			System.out.println(result);
		}
	}


}