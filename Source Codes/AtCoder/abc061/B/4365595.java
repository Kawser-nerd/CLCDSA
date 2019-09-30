import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] numArray = new int[50 + 1];
        for(int i = 0; i < m; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            numArray[a]++;
            numArray[b]++;
        }

        for(int i = 1; i <= n; i++){
            System.out.println(numArray[i]);
        }
    }    
}