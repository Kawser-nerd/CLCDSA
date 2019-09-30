import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num_divisor[] = new int[1001];
        
        for (int i = 2; i <= n; i++){
            int divisor = 2;
            int i2 = i;
            while (i2 != 1){
                //System.out.println(i2);
                while(i2 % divisor == 0){
                    i2 /= divisor;
                    num_divisor[divisor]++;    
                }
                divisor++;
            }
        } 
        long ans = 1;
        for (int i = 2; i <= n; i++){
            if (num_divisor[i] != 0) ans = (ans * (num_divisor[i] + 1)) % 1000000007;
        }
        System.out.println(ans);
    }
}