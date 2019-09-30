import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String t = sc.next();
        int N = s.length();
        int M = t.length();
        char[] S = new char[N];
        char[] T = new char[M];
        
        for(int i = 0; i < N; i++) S[i] = s.charAt(i);
        for(int i = 0; i < M; i++) T[i] = t.charAt(i);
        
        //????????????
        Arrays.sort(S);
        Arrays.sort(T);
        
        //??????????for?????
        int loop = 0;
        if(N <= M){
            loop = N; 
        }else{
            loop = M;
        }
        
        //S[]????T[]???????????
        for(int i = 0; i < loop; i++){
            if(S[i] < T[(M - 1) - i]){
                System.out.println("Yes");
                return;
            }else if(S[i] > T[i]){
                System.out.println("No");
                return;
            }else{
                continue;   
            }
        }
        //????????????????
        System.out.println(N < M ? "Yes" : "No");
    }
}