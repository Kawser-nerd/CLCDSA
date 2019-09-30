import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = "";
        solve(N, S);
    }
    public static void solve(int n, String s){
        if(n == 0){
            System.out.println(s); 
        }else{
            solve(n-1, s+"a");
            solve(n-1, s+"b");
            solve(n-1, s+"c");
        }
    }
}