import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int C = Integer.parseInt(sc.next());
        
        int res = 0;
        
        if((A+B) >= C){
            res = C+B;
        }else{
            res = B * 2 + Math.min(C - B, A + 1);
        }
        
        System.out.println(res);
    }
}