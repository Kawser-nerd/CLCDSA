import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
    	try(Scanner sc = new Scanner(System.in)) {

    		int X = sc.nextInt();
    		int Y = sc.nextInt();
    		System.out.println(X+Y/2);

    	}
    }
}