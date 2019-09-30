import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        
        for(int i = 0; i < M; i++){
            A[i] = sc.nextInt();
        }
        
        int count = 0;
        for(int i = 0; i < M; i++){
            if(X > A[i]){
                count++;
            }
        }
        System.out.println(Math.min(count,M-count));
    }
}