import java.util.*;

class Main{       
   public static void main(String[] args){
     
      Scanner sc = new Scanner(System.in);                                            
  
      Deque<Integer> q = new ArrayDeque<Integer>();
      
      int n = sc.nextInt();
      
      int a[] = new int[n];
      for(int i = 0;i < n;i++){
          a[i] = sc.nextInt();
      }
      
      if(n%2 == 0){
          for(int i = 0;i < n;i++){
             if(i%2 == 1){
                 q.addFirst(a[i]);
             }else{
                 q.addLast(a[i]);
             }
          }          
      }else{
          for(int i = 0;i < n;i++){
              if(i%2 == 1){
                  q.addLast(a[i]);
              }else{
                  q.addFirst(a[i]);
              }
          }
      }
      
      while(!q.isEmpty()){
          System.out.print(q.poll());
          System.out.print(" ");
      }
     
      System.out.println();
       
      
   }
}