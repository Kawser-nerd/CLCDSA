import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        
        int max = Math.max(Math.max(A,B),C);
        int sum = A + B + C - max;
        
        for(int i = 0; i < K; i++){
            max *= 2; 
        }        
        
        System.out.println(max + sum);
    }
}