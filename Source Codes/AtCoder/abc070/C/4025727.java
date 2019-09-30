import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long A = sc.nextLong();
        for(int i = 0; i < N-1;i++){
            long B = sc.nextLong();
            long a = A;
            long b = B;
            while(a%b != 0){
                long tmp = a;
                a = b;
                b = tmp%b;
            }
            A = A/b*B;
        }
        System.out.println(A);
    }
}