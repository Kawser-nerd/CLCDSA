import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int N = Integer.parseInt(sc.next());
        
        int T = Integer.parseInt(sc.next());
        int A = Integer.parseInt(sc.next());
        
        int res = 0;
        double cnt = Integer.MAX_VALUE;
        
        for(int i = 0; i < N; i++){
            String s = sc.next();
            
            double d = Math.abs(A - (T - Integer.parseInt(s) * 0.006));
            
            if(cnt > d){
               cnt = d;
               res = i+1;
            }
        }
        
        System.out.println(res);
    }
}