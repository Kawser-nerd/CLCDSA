import java.util.*;

public class Main {
        
  public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
   
       int N = sc.nextInt();
      
       int count = 0;
       
       HashSet<Integer> set = new HashSet<>();
       
       for(int i = 0;i < N;i++){
           int a = sc.nextInt();
           if(set.contains(a)){
               count++;
           }else{
              set.add(a);
           }
       }
              
       System.out.println(N - ( count + (count%2 == 0 ? 0 : 1 )));

  }  
}