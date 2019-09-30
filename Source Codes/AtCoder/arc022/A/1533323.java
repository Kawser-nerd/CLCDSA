import java.util.*;

public class Main{             
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);
        
        String S = sc.next().toUpperCase();
       
        char[] array = new char[]{'I','C','T'};
        
        int index = 0;
        
        for(int i = 0;i < S.length();i++){
            char c = S.charAt(i);
            
            if(c == array[index]){
                if(index == 2){
                    System.out.println("YES");
                    return;
                }                
                index++;
            }            
        }
        
        System.out.println("NO");
        
    }        
}