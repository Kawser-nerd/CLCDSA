import java.util.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int a = scan.nextInt();
      	int b = scan.nextInt();
      	int c = scan.nextInt();
      	int m = 100 * a + 10 * b + c;
      	if(m % 4 == 0){
        	System.out.print("YES");
        }
      	else{
        	System.out.print("NO");
        }
    }
	
}