import java.util.*;

public class Main {
	
  	public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
      	String input = sc.nextLine();
      	if(input.substring(0,1).equals(input.substring(2,3))) {
          	System.out.println("Yes");
        }
      	else {
          System.out.println("No");
        }
      
    }

}