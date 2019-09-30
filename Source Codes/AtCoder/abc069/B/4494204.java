import java.util.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	String s = scan.nextLine();
      	int size = s.length();
      	char a = s.charAt(0);
      	char z = s.charAt(size - 1);
      	System.out.print(a);
      	System.out.print(size - 2);
      	System.out.print(z);
      	scan.close();
    } 
}