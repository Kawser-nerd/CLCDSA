import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String s = sc.nextLine();
        
        int res = Integer.MAX_VALUE;
        
        for(int i = 0; i < s.length() - 2; i++){
            int j = Integer.parseInt(s.substring(i,i+3));
            int k = Math.abs(753 - j);
            
            if(res >= k){
                res=k;
            }
        }
        System.out.println(res);
    }
}