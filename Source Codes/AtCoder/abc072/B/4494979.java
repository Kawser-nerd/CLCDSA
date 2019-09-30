import java.util.*;
import java.lang.*;

public class Main{
	public static void main(String[] args){
    	Scanner scan = new Scanner(System.in);
      	String s = scan.next();
      	int some = roundup(s.length());
      	char[] ans = new char[some];
      	for (int i = 0; i < some; i++){
       		ans[i] = s.charAt(i * 2);
        }
      	System.out.print(ans);
    }
  	public static int roundup(int x){
      	int ans = 0;
      	if(x % 2 == 0){
        	ans = x / 2;
        }
      	else{
        	ans = x / 2 + 1; 
        }
      	return ans;
    }
}