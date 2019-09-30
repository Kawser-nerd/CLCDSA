import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        char[] s = sc.nextLine().toCharArray();
        int[] d = new int[26];
        
        for(int i=0; i<s.length; i++){
            int c = (int)s[i] - (int)'a';
            d[c] += 1;
        }
        
        int odd = 0;
        int eve = 0;
        for(int i=0; i<d.length; i++){
            int t = d[i];
            if(t>0){
                eve += t/2;
                odd += t%2;
            }
        }
        
        if(odd > 0){
            System.out.println(eve/odd*2 + 1);
        }else{
            System.out.println(s.length);
        }
    }
}