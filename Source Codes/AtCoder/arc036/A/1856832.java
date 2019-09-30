import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int[] rui = new int[n+1];
        int sum = 0;
        for(int i=0; i<n; i++){
            int tmp = sc.nextInt();
            sum += tmp;
            rui[i+1] = sum;
        }
        
        int[] sui = new int[n-3];
        for(int i=0; i<sui.length; i++){
            sui[i] = rui[i+3]-rui[i];
        }
        
        int ans = -1;
        for(int i=0; i<sui.length; i++){
            if(sui[i] < k){
                ans = i+3;
                break;
            }
        }
        
        System.out.println(ans);
    }
}