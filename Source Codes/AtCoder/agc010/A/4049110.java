import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int odd = 0;
        for (int i = 0; i < N; i++) {
        	int a = sc.nextInt();
        	if (a % 2 == 1) {
        		odd++;
        	}
        }
        odd = odd % 2;
        
        System.out.println(odd == 1 ? "NO": "YES");
    }
}