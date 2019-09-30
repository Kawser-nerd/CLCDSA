import java.util.Scanner;



public class Main {
  public static void main (String[] args) {
    Scanner reader = new Scanner(System.in);
    int A = reader.nextInt();
    int B = reader.nextInt();
    if (A % 2 == 0 ||B % 2 == 0  ) {
    	System.out.print("No");
    }else {
    	System.out.print("Yes");
    }
}
  
}