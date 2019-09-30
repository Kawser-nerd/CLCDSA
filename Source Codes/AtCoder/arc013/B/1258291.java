import java.util.*;

public class Main { 
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int N = sc.nextInt();                                                                                    
                       
            int maxD[] = new int[3];
            
            
        for(int i = 0;i < N;i++){ 
            int d[] = new int[3];
            for(int j = 0 ;j< 3;j++){
                d[j] = sc.nextInt();
            }
            Arrays.sort(d);
            for(int k = 0;k < 3;k++){
                maxD[k] = Math.max(maxD[k],d[k]);
            }
        }   
          
        System.out.println(maxD[0]*maxD[1]*maxD[2]);
            
        }             
}