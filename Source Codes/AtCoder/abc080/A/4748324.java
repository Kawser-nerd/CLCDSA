import java.util.*;
public class Main{
    
    public static void main(String[] args){
        int N,A,B,K;
        Scanner Sc = new Scanner(System.in);
        N = Sc.nextInt();
        A = Sc.nextInt();
        B = Sc.nextInt();
        K = N * A;
        if (K > B){
            System.out.println(B);
        }else{
            System.out.println(K);    
        }
    }
}