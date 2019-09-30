import java.util.*;

public class Main {                   
    
  public static void main(String[] args) {                     
    Scanner sc = new Scanner(System.in);
      
    HashSet<String> used = new HashSet<String>();
    
    int N = sc.nextInt();

    String last = "";
    
    boolean first = false;
    boolean second = false;
    
    boolean flag = false;
    
    for(int i = 0;i < N;i++){
      String W = sc.next();
      if(i%2 == 0){
          if(used.contains(W)){
              if(!flag){                  
                 second = true;
                 flag = true;
              }              
          }          
          if(i != 0 && W.charAt(0) != last.charAt(last.length() - 1)){
              if(!flag){
                second = true;
                flag = true;
              }
          }          
          used.add(W);
      }else{
          if(used.contains(W)){
              if(!flag){
               first = true;
               flag = true;
              }
          }
          if(i != 0 && W.charAt(0) != last.charAt(last.length() - 1)){
              if(!flag){
               flag = true;
               first = true;
              }
          }                    
          used.add(W);
      }              
      last = W;
    } 
    
    if(!flag){
        System.out.println("DRAW");
        return;
    }
   
    if(first){
      System.out.println("WIN");
      return;
    }else{
      System.out.println("LOSE");        
      return;
    }
    
  }      
}