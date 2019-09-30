import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double T = sc.nextDouble();
	    double X= sc.nextDouble();
		double x = 0;
		if((1<=T&&T<=100)&&(1<=X&&X<=100)) {
	 x = T / X;
	}
	System.out.println(x);
	}
}