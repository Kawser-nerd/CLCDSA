import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
      
     ArrayList<Integer> ans = new ArrayList<Integer>();
     
     int N = sc.nextInt();
     int M = sc.nextInt();
     
     
     
     for(int i = 1;i <= N;i++){
         if(i == M){
             continue;
         }
         ans.add(i);
     }
     
     System.out.println(ans.get(0));     
     
  }                            
}