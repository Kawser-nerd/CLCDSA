import java.util.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	String s = scan.next();
      	int counter = 0;
      	if(s.charAt(0) == 'o'){
        	counter++;
        }
      	if(s.charAt(1) == 'o'){
        	counter++;
        }
      	if(s.charAt(2) == 'o'){
        	counter++;
        }
      	System.out.print(700 + counter * 100);
    }
}