import java.util.*;

public class Main{             
    public static void main(String[] args){
      
         Scanner sc = new Scanner(System.in);
         
         String S = sc.next();
         
         boolean iflag = false;
         boolean cflag = false;
         boolean tflag = false;
                  
         for(int i = 0;i < S.length();i++){
              
              if(S.charAt(i) == 'i' || S.charAt(i) == 'I'){
                  iflag = true;
                  continue;
              }
              
              if(iflag && (S.charAt(i) == 'c' || S.charAt(i) == 'C')){
                  cflag = true;
                  continue;
              }

              if(cflag && (S.charAt(i) == 't' || S.charAt(i) == 'T')){
                  tflag = true;
                  break;
              }
              
         }
         
         if(iflag && cflag && tflag){
             System.out.println("YES");
         }else{
             System.out.println("NO");             
         }
         
        
    }        
}