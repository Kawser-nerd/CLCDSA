import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int[] A = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
        int min = Integer.MAX_VALUE;
        
        // ????????
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j == i) continue;
                
                for(int k = 0; k < 3; k++){
                    if(k == i || k == j) continue;

                    int cost = Math.abs(A[i] -A[j]) + Math.abs(A[j] - A[k]);
                    if(min > cost) min = cost;
                }
            }
        }
        System.out.println(min);
    }
}