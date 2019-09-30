import java.util.*;

public class Main {                    
    
  public static void main(String[] args) {   
     
      Scanner sc = new Scanner(System.in);                                                                                     
    
      int N = sc.nextInt();
      int M = sc.nextInt();
      
      String name = sc.next();
      String kit  = sc.next();
      
      char n[] = new char[26];
      char m[] = new char[26];
      
      for(int i = 0;i < N;i++){
          char nc = name.charAt(i);          
          n[nc - 'A']++;
      }
      
      for(int i = 0;i < M;i++){
          char nk = kit.charAt(i);
          m[nk - 'A']++;          
      }
      
      int an = Integer.MIN_VALUE;            
                        
      for(int i = 0;i < N;i++){
          char target = name.charAt(i);          
          int count = 0;
          
          if(m[target - 'A'] == 0){
              System.out.println(-1);
              return;
          }
          
          if(n[target - 'A']%m[target - 'A'] == 0){
             count = n[target - 'A']/m[target - 'A'];
          }else{
             count = n[target - 'A']/m[target - 'A'] + 1;
          }
          an = Math.max(an,count);
      }      
      
      System.out.println(an);
     
  }             
}