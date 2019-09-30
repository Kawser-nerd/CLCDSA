import java.util.*;

public class Main { 
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int N = sc.nextInt();
            
            long a[] = new long[N];
            long b[] = new long[N];
            
            for(int i = 0 ;i < N;i++){                                                
                a[i] = sc.nextLong();
                b[i] = sc.nextLong();
            }
                  
            int count = 0;
            for(int i = 0 ;i < N;i++){
                for(int k = i;k < N;k++){
                   for(int j = k;j <N;j++){
                       long s = Math.abs((a[j] - a[i])*(b[k] - b[i]) - (a[k] - a[i])*(b[j] - b[i]));
                        
                       if(s != 0 && s % 2 == 0)
                             count++;
                                             
                       
                   }                    
                }                                
            }
            
            System.out.println(count);
                                
        }             
        

        
}