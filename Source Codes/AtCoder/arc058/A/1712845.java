import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
      
      int N = sc.nextInt();
      
      int K = sc.nextInt();
      String a[] = new String[K];
      
      for(int i = 0;i < K;i++){
          a[i] = sc.next();
      }
     
     for(int i = N;;i++){
       String val = String.valueOf(i);
       boolean flag = true;
       for(int j = 0;j< K;j++){
         if(val.contains(a[j])){
             flag = false;
         }
       }
       if(flag){
         System.out.println(i);   
         return;
       }         
     }
      
      
      
   }
}