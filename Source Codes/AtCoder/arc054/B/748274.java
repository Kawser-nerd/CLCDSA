import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double p = sc.nextDouble();
		System.out.println(calcTime(p));
		sc.close();
	}

	static double calcX(double p){
		return (Math.log(p*Math.log(2)/1.5) * 1.5)/Math.log(2);
	}
	static double calcTime(double p){
		double x = calcX(p);
		if(x < 0 ) return p;
		else return x + p * Math.pow(2, -x/1.5);
	}
}