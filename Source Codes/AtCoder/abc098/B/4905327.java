import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        String s = sc.next();
        
        int max = 0;
        
        for(int i = 1; i < s.length(); i++){
            String temp = s.substring(0,i);
            
            Set<Character> set = new HashSet<Character>();
            
            for(char c : temp.toCharArray()){
                set.add(c);
            }
            
            String str = s.substring(i,s.length());
            
            int cnt = 0;

            for(char c : set){
                for(char ch : str.toCharArray()){
                    if(c == ch){
                        cnt++;
                        break;
                    }
                }
            }
            max = Math.max(max,cnt);
        }
        
        System.out.println(max);
    }
}