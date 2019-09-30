import java.util.*;
public class Main {
	public static void main(String[] args){
		// get numbers
		Scanner sc = new Scanner(System.in);        
		int a = sc.nextInt();
		int b = sc.nextInt();
        
        int count = 0;
        int t = 0;

        // 10, 5, 1
        t = Math.abs(a-b);
        
        if (t > 10) {
            count = t/10;
            t = t%10;
        } 
        if (t > 7) {
            count += Math.abs(t-10) + 1;
            t = 0;
        } 
        if (t > 3) {
            count += Math.abs(t-5) + 1;
        } else {
            count += t;
        }

		// output
        System.out.println(count);
	}
}