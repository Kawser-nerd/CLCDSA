import java.util.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	int r = scan.nextInt();
      	int b = scan.nextInt();
      	int g = scan.nextInt();
      	int s = 100 * r + 10 * b + g;
      	if(s % 4 == 0){
        	System.out.print("YES");
        }
      	else{
        	System.out.print("NO");
        }
    }
}