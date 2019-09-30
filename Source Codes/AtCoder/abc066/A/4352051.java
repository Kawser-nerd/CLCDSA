import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int[] sum = {a + b, b + c, c + a};
        int min = Integer.MAX_VALUE;
        
        for(int i = 0; i < 3; i++){
            if(min > sum[i]) min = sum[i];
        }
        
        System.out.println(min);
    }
}