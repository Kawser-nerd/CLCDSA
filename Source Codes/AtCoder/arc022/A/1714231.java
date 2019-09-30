import java.util.*;

class Main{           
    
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                                          
       
       String S = sc.next();
       
       boolean iflag = false;
       boolean cflag = false;
       boolean tflag = false;
       
       for(int i = 0;i < S.length();i++){
           
           if(S.charAt(i) == 'I' || S.charAt(i) == 'i'){
               iflag = true;
               continue;               
           }
           
           if(iflag && (S.charAt(i) == 'C' || S.charAt(i) == 'c')){
               cflag = true;
               continue;
           }
           
           if(cflag && (S.charAt(i) == 'T' || S.charAt(i) == 't')){
               tflag = true;
               continue;
           }
           
       }
       
       if(iflag && cflag && tflag){
           System.out.println("YES");
       }else{
           System.out.println("NO");           
       }
       
   }
   
 }