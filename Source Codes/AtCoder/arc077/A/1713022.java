import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
  
      Deque<Integer> q = new ArrayDeque<Integer>();
      
      int n = sc.nextInt();
                  
      for(int i = 0;i < n;i++){
          int a = sc.nextInt();
             if(i%2 == 0){
                 q.addLast(a);
             }else{
                 q.addFirst(a);
             }
      }
      

   if(n%2 == 0){
      while(!q.isEmpty()){
          System.out.print(q.poll());
          System.out.print(" ");
      }
   }else{
      while(!q.isEmpty()){
          System.out.print(q.pollLast());
          System.out.print(" ");
      }             
   }
     
      System.out.println();
      
   }
}