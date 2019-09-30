import java.util.*;

public class Main {           
    public static void main(String[] args) {		        
       Scanner sc = new Scanner(System.in);               
       
       int N = sc.nextInt();       
       int M = sc.nextInt();
       
       int [] cdCase = new int[N+1];
       
       for(int i = 0; i < N+1;i++){
           cdCase[i] = i;
       }
       
       for(int i = 0;i < M;i++){           
           int disk  = sc.nextInt();
           int index = 0;
           
           for(int j = 0; j < N + 1; j++) {
               if(cdCase[j] == disk) {
                  index = j;
                  break;
               }
           }
           
           cdCase[index] = cdCase[0];
           cdCase[0] = disk;                                 
       }
       
       for(int i = 1;i < N+1;i++){
           System.out.println(cdCase[i]);
       }
       
    }           
}