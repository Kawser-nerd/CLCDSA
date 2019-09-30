import java.util.*;

public class Main{             
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int count = 0;
        
        for(int i = 0;i < N;i++){
            String S = sc.next();
            
            String plus = "";
            
            if(i == N-1){
                plus = ".";
            }
            
            if(S.equals("TAKAHASHIKUN" + plus)){
               count++;         
            }else if(S.equals("Takahashikun" + plus)){
               count++;
            }else if(S.equals("takahashikun" + plus)){
               count++;
            }            
        }
       
        System.out.println(count);                      
        
    }        
}