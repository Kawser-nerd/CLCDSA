import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		
		double money_sum=0;
		for(int i=0;i<N;i++) {
			String[] list = sc.nextLine().split(" ");
			double money = Double.parseDouble(list[0]);
			String value = list[1];
			if(value.equals("JPY")) {
				money_sum += money;
			}
			else {
				money_sum += money * 380000.0;
			}
		}
		
        System.out.println(money_sum);
	}
}