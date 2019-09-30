import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double C = sc.nextDouble();
        double D = sc.nextDouble();
        double a = B/A;
        double b = D/C;
        if (a == b) {
        	System.out.println("DRAW");
        } else if (a > b) {
        	System.out.println("TAKAHASHI");
        } else {
        	System.out.println("AOKI");
        }
    }
}