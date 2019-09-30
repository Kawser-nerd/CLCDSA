import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[] map = new int[3];
        int sum = 0;
        for (int i = 0; i < 3; i++) {
        	map[i] = sc.nextInt();
        	sum += map[i];
        }
        
        int min = sum;
        for (int a: map) {
        	min = Math.min(min, sum - a);
        }
        
        System.out.println(min);
    }
}