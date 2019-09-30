import java.util.*;
import java.io.*;

public class Main {
    public static int solve(int A, int B){
        int ans = Integer.MAX_VALUE;
        for(int one=-4;one<=4;one++){
        	for(int five=-1;five<=1;five++){
        	    for(int ten=-10;ten<=10;ten++){
        	        if(A+one+5*five+10*ten==B) ans = Math.min(ans, Math.abs(one)+Math.abs(five)+Math.abs(ten));
        	    }
        	}
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        System.out.println(solve(A,B));
    }
}