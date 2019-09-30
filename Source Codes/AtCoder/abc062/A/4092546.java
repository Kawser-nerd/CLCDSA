import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[] map = {1,3,1,2,1,2,1,1,2,1,2,1};
        
        int x = sc.nextInt();
        int y = sc.nextInt();
        
        System.out.println(map[x-1] == map[y-1] ? "Yes": "No");
    }
}