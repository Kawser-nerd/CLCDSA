import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String t = sc.next();
        int N = s.length();
        int M = t.length();
        char[] S = s.toCharArray(); //String s?char???????
        char[] T = t.toCharArray(); //String t?char???????
        
        //????????????
        Arrays.sort(S);
        Arrays.sort(T);
        
        //???????????S????T???????
        String ss = "";
        String tt = "";
        for(int i = 0; i < N; i++) ss += S[i];
        for(int i = 0; i < M; i++) tt += T[(M - 1) -i];

        //????????compareTo()???
        System.out.println(ss.compareTo(tt) < 0 ? "Yes" : "No");
    }
}