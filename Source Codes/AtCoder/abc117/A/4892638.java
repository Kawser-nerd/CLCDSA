import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int X = sc.nextInt();
		
		double t =(double) T / X;

		System.out.println(String.format("%.5f", t));
    }
}