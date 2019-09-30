import java.util.*;

public class Main{ 
        
    public static void main(String[] args){
      
       Scanner sc = new Scanner(System.in);
       
       int N = sc.nextInt();
       int M = sc.nextInt();
       int A = sc.nextInt();
       int B = sc.nextInt();
       
       int c[] = new int[M];
       
       for(int i = 0;i < M;i++){
           c[i] = sc.nextInt();           
       }              
       
       int card = N;
       for(int i = 0;i < M;i++){
           if(card <= A){
               card += B;
           }
           
           card -= c[i];
           
           if(card < 0){
              System.out.println(i+1);   
              return;
           }           
       }
       
       System.out.println("complete");
       
    }    
}