import java.util.*;

public class Main {
	
  	public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
      	String input = sc.nextLine();
      	String[] inputs = input.split(" ");
      	int a = Integer.valueOf(inputs[0]);
      	int b = Integer.valueOf(inputs[1]);
      	int c = Integer.valueOf(inputs[2]);
      	int d = Integer.valueOf(inputs[3]);
      	int start = 0; 
      	int stop = 0;
     	if(a>=c) {
          start = a;
        }
      	else {
          start = c;
        }
      
      if(b<=d) {
        stop = b;
      }
      else {
        stop = d;
      }
      
      if(start>=stop) {
        System.out.println("0");
      }
      else {
      	System.out.println(stop-start);
      }
      
      
      
      
      
    }

}