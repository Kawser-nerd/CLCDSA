import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
       //[a-z]?26???????
        int[] ch = new int[26];
      
        //????0?
        for(int i = 0; i < 26; i++) ch[i] = 0;  
        
        //[a-z]????????
        for(int i = 0; i < S.length(); i++){
            int num = S.charAt(i) - 'a';
            ch[num]++;
        }
        
        //[a-z]????2??????false?? 
        boolean state = true;
        for(int i = 0; i < 26; i++){
            if(ch[i] > 1){
                state = false;
                break;
            }
        }
        System.out.println(state ? "yes" : "no");
    }
}