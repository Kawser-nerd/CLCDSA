import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    double h = scanner.nextDouble();
    double bmi = scanner.nextDouble();
    System.out.println(h*h*bmi/10000);
  }
}