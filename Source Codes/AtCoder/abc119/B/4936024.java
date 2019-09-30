import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		double sum=0;

		double BTC=380000.0;

		int N=sc.nextInt();

		for(int i=0;i<N;i++) {

			double money=sc.nextDouble();
			String money_type=sc.next();

			if(money_type.equals("JPY")) sum+=money;
			else sum+=money*BTC;

		}

		System.out.println(sum);

		sc.close();

	}

}