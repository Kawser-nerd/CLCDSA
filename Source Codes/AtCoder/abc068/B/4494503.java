import java.util.*;
import java.lang.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int a = scan.nextInt();
      	int counter = 0;
      	
      	double x = Math.log(a) / Math.log(2);
      	int num = (int)x;
      
      	System.out.print((int)Math.pow(2, num));
      	
    }
}