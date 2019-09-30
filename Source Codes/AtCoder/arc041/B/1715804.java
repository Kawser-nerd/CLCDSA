import java.util.*;

class Main{           
    
   public static void main(String[] args){
       Scanner sc= new Scanner(System.in); 
       
       int N = sc.nextInt();
       int M = sc.nextInt(); 
       
       int b[][] = new int[N][M];
       
       for(int i = 0;i < N;i++){
         String str = sc.next();
         for(int j = 0;j < M;j++){
            b[i][j] = Integer.parseInt(str.substring(j,j+1));
         }
       }
       
       int ret[][] = new int[N][M];
       
       for(int i = 1;i < N-1;i++){
           for(int j = 1;j < M-1;j++){
               int min = 10;
               min = Math.min(b[i][j-1],min);
               min = Math.min(b[i-1][j],min);
               min = Math.min(b[i+1][j],min);
               min = Math.min(b[i][j+1],min);
               b[i][j-1] -= min;
               b[i-1][j] -= min;
               b[i+1][j] -= min;
               b[i][j+1] -= min;
               ret[i][j] = min;
           }           
       }
       
       for(int i = 0;i < N;i++){
          for(int j = 0;j < M;j++){
              System.out.print(ret[i][j]);   
          }       
          System.out.println();
      }
       
       
    }
      
 }