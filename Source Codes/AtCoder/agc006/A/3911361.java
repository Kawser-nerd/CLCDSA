import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {

    public static int solve(int N, String S, String T){
        for(int single=0; single<=N; single++){
            boolean flag = true;
            for(int i=0; i<N-single; i++){
                if(S.charAt(i+single)!=T.charAt(i)) flag=false;
            }
            if(flag) return N+single;
        }
        return 2*N;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        String T = sc.next();
        System.out.println(solve(N,S,T));


    }
}