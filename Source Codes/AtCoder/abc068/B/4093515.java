import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int ans = 1;
        for (int i = 2; i <= N; i*=2) {
        	ans = i;
        }
        
        System.out.println(ans);
    }
}