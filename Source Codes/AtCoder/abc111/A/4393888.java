import java.util.Scanner;

public class Main {
	public static void main(String args[]) {

		Scanner scan = new Scanner(System.in);
		String num = scan.next();

		String no1= num.substring(0,1);
		String no2 = num.substring(1,2);
		String no3 = num.substring(2,3);
		if(!no1.equals("1")) {
			no1="1";
		}else if(!no1.equals("9")) {
			no1 ="9";
		}

		if(!no2.equals("1")) {
			no2="1";
		}else if(!no2.equals("9")) {
			no2 ="9";
		}

		if(!no3.equals("1")) {
			no3="1";
		}else if(!no3.equals("9")) {
			no3 ="9";
		}


	System.out.println(no1+no2+no3);
	}
}