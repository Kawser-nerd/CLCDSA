import java.util.*;

public class Main { 
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int N = sc.nextInt();
            
            int K = sc.nextInt();
            
            int a[] = new int[N];
            
            for(int i = 0 ;i < N;i++){
                a[i] = sc.nextInt();
            }
            
            int count = 0;
            int up = 1;            
            
            for(int i = 0 ;i <N;i++){
                
                if(i > 0 && a[i-1] < a[i]){
                    up++;
                }else{
                    up = 1;
                }
                
                if(up >= K){
                    count++;
                }
                                
            }
                        
            System.out.println(count);

        }             
}