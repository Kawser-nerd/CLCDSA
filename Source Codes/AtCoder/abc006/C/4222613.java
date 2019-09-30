import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int s=(M-2*N)/2;
        for (int k = 0; k <=s; k++) {
            int j=M-2*(N+k);
            int i=N-j-k;
            if(i>=0&&j>=0&&i+j+k==N){
                out.println(i+" "+j+" "+k);
                exit(0);
            }
        }
        out.println("-1 -1 -1");
    }
}