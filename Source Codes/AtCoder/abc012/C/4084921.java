import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        int sum = 0;
        for (int i = 1; i < 10; i++) {
        	for (int j = 1; j < 10; j++) {
        		sum+=i*j;
        	}
        }
        
        int sub = sum - N;
        for (int i = 1; i < 10; i++) {
        	for (int j = 1; j < 10; j++) {
        		if (sub == i*j) {
        			System.out.println(i + " x " + j);
        		}
        	}
        }
    }
}