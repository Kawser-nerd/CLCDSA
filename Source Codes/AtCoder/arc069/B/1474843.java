import java.util.*;

public class Main {          
    
    static int N;
    static char[] cs;    
    
    public static void main(String[] args){           
        
         Scanner sc = new Scanner(System.in);
   
         N = sc.nextInt();         
         
         String S = sc.next();
         
         cs = S.toCharArray();
    
         for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                
                int a[] = new int[N];  
                
                a[0] = i;
                a[1] = j;
                 
                if(cal(a)){                                                                                    
                     for(int k = 0;k < N;k++){
                         if(a[k] == 1){
                             System.out.print("S");
                         }else{
                             System.out.print("W");                             
                         }
                     }
                     System.out.println();
                     return;
                }                                                   
                 
            }
         }           
         
         System.out.println(-1);
         
  }    
    
   static boolean cal(int[] a){
       
            for (int i = 2; i < N; i++) {
                if (cs[i - 1] == 'o') {
                    if (a[i - 1] == 1) {
                        a[i] = a[i - 2];
                    } else {
                        a[i] = a[i - 2] ^ 1;
                    }
                } else {
                    if (a[i - 1] == 1) {
                        a[i] = a[i - 2] ^ 1;
                    } else {
                        a[i] = a[i - 2];
                    }
                }
            }

            if (a[0] == 1) {
                if (cs[0] == 'o') {
                    if (a[1] != a[N - 1]) return false;
                }
                if (cs[0] == 'x') {
                    if (a[1] == a[N - 1]) return false;
                }
            } else {
                if (cs[0] == 'o') {
                    if (a[1] == a[N - 1]) return false;
                }
                if (cs[0] == 'x') {
                    if (a[1] != a[N - 1]) return false;
                }
            }

            // check n-1
            if (cs[N - 1] == 'o') {
                if (a[N - 1] == 1) {
                    return a[N - 2] == a[0];
                } else {
                    return a[N - 2] != a[0];
                }
            } else {
                if (a[N - 1] == 1) {
                    return a[N - 2] != a[0];
                } else {
                    return a[N - 2] == a[0];
                }
            }            
    }                              
}