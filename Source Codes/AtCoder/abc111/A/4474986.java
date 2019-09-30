import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	String N = input.next();
      	N = N.replace('1', '2');
      	N = N.replace('9', '1');      
      	N = N.replace('2', '9');
      System.out.print(N);

    }
  	
}