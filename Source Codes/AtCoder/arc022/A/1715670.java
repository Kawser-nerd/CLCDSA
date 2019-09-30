import java.util.*;

class Main{           
    
   public static void main(String[] args){
        Scanner sc= new Scanner(System.in); 
       
        String S = sc.next();
        
        if(S.toLowerCase().matches("^.*i.*c.*t.*$")){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        
       
    }
      
 }