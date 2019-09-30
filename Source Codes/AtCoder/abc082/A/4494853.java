import java.util.*;
 
public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int a = scan.nextInt();
      	int b = scan.nextInt();
      	int x = a + b;
      	int ans = 0;
      	if(x % 2 == 0){
        	ans = x / 2;
        }
      	else{
        	ans = x / 2 + 1;
        }
      	
      	System.out.print(ans);
    }
}