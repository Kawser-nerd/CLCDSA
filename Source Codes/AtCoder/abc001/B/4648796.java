import java.util.*;
public class Main {
	public static void main(String[] args){
		// get numbers
		Scanner sc = new Scanner(System.in);     
		double m = sc.nextInt() * 0.001;
        double a = 0;

        if (0.1 <= m && m <= 5) {
            a = m * 10;
        } else if (6 <= m && m <= 30) {
            a = m + 50;
        } else if (35 <= m && m <= 70) {
            a = (m - 30)/5 + 80;
        } else if (70 <= m) {
            a = 89;
        }

		// output
        System.out.printf("%02.0f", a);
        System.out.println();
        sc.close();
	}
}