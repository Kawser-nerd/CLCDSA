import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		double[] money = new double[10];
		String[] dep = new String[10];

		for(int i = 0 ; i < N ; i++){
			money[i] = sc.nextDouble();
			dep[i] = sc.next();
		}

		sc.close();

		double ans=0.0;
		for(int i = 0 ; i < N ; i++){
			if(dep[i].equals("JPY")){
				ans += money[i];
			}
			else{
				ans += money[i] * 380000.0;
			}
		}

		System.out.println(ans);

	}
}