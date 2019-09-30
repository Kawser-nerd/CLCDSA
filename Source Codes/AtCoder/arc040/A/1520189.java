import java.util.*;

public class Main{            
    
     public static void main(String[] args){
      
         Scanner sc = new Scanner(System.in);
         
         int N = sc.nextInt();
         
         char a[][] = new char[N][N];
         
         for(int i = 0;i < N;i++){
             String str = sc.next();
             for(int j = 0;j < N;j++){
                 a[i][j] = str.charAt(j);
             }
         }
         
         int rcnt = 0;
         int bcnt = 0;         
         
         for(int i = 0;i < N;i++){
             for(int j = 0;j < N;j++){
                 if(a[i][j] == 'R'){
                        rcnt++;
                 }else if(a[i][j] == 'B'){
                        bcnt++;
                 }                 
             }             
         }                                    
         
         
         if(rcnt == bcnt){
             System.out.println("DRAW");
             return;
         }else if(rcnt > bcnt){
             System.out.println("TAKAHASHI");
             return;
         }else if(bcnt > rcnt){
             System.out.println("AOKI");             
             return;
         }
         
                  
     }              
}