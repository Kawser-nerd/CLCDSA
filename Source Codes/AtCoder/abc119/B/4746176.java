import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double [] xArray = new double [n];
		String [] uArray = new String [n];
		double sum = 0;
		for(int i = 0; i < n; i++) {
			xArray[i] = sc.nextDouble();
			uArray[i] = sc.next();
			if(uArray[i].equals("JPY")) sum = sum + xArray[i];
			else if(uArray[i].equals("BTC")) sum = sum + xArray[i]*380000.0;
		}
		System.out.printf("%f\n", sum);
		sc.close();
	}

}