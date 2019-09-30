import java.util.*;

public class Main{     
        
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);                                               
        
        String S = sc.next();
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
                
        
        S = S.substring(0,D) + "\"" + S.substring(D);
        S = S.substring(0,C) + "\"" + S.substring(C);        
        S = S.substring(0,B) + "\"" + S.substring(B);                
        S = S.substring(0,A) + "\"" + S.substring(A);                
        
        System.out.println(S);
                                
    }        
}