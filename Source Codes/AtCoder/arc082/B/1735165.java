import java.util.*;

class Main{            
     
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);  
       
       int N = sc.nextInt();
       int count = 0;
       
       int a[] = new int[N+1];
       
       for(int i = 1;i <= N;i++){
           a[i] = sc.nextInt();
       }
       
       for(int i = 1;i <= N;i++){
           if(i == a[i]){
               count++;
               i++;
           }           
       }
       
       System.out.println(count);
    
       
       
   }
}