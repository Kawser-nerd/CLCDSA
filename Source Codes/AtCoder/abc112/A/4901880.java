import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
    	try(Scanner sc = new Scanner(System.in)) {

    		int N = sc.nextInt();
    		if(N == 1)	System.out.println("Hello World");
    		else {
    			int a = sc.nextInt();
    			int b = sc.nextInt();
    			System.out.println(a+b);
    		}

    	}
    }
}