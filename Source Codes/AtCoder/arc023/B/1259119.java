import java.util.*;

public class Main { 
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int R = sc.nextInt();
            int C = sc.nextInt();
            int D = sc.nextInt();
            
            int a[][] = new int[R][C];
            
            for(int i = 0 ;i < R;i++){
                for(int j = 0 ;j < C;j++){
                   a[i][j] = sc.nextInt();                    
                }                
            }
            
            int max = 0;
            for(int i = 0 ;i < R;i++){
                for(int j = 0;j < C;j++){
                    if((i + j) <= D && (i+j)%2 == D%2){
                        max = Math.max(max,a[i][j]);
                    }                    
                }                                
            }
            
            System.out.println(max);            
                                
        }                             
}