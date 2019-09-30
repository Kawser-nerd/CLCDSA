import java.util.*;

class Main{       
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                            
              
       HashSet<Integer> first = new HashSet<Integer>();
       HashSet<Integer> second = new HashSet<Integer>();
       
       int N = sc.nextInt();       
       int M = sc.nextInt();
       
       for(int i = 0;i < M;i++){
         int a = sc.nextInt();
         int b = sc.nextInt();
         if(a == 1){
             first.add(b);
         }
         if(b == N){
             second.add(a);
         }         
       }
       
       for(Integer k:first){
           if(second.contains(k)){
               System.out.println("POSSIBLE");
               return;
           }
       }
             
       System.out.println("IMPOSSIBLE");
       
   }
}