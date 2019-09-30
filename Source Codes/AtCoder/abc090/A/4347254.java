import java.util.*;

public class Main {
	public static void main(String args[]) { 
    	Scanner sc = new Scanner(System.in);
    	String input1 = sc.nextLine();
        String input2 = sc.nextLine();
        String input3 = sc.nextLine();
       	System.out.println(input1.substring(0,1)+input2.substring(1,2)+input3.substring(2,3));
    }
}