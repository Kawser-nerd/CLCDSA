import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int K = input.nextInt();
      	int odds = (K + 1) / 2;
        int evens = K / 2;
      	System.out.print(odds * evens);
    }
}