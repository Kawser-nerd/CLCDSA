import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] i = new int[N];

        for(int j = 0; j < N; j++){
            i[j] = sc.nextInt();
        }
        long answer = gcd(i[0],i[1]);

        for(int j = 2; j < N; j++){
            answer = gcd(answer,i[j]);
        }

        System.out.println(answer);
    }

    public static long gcd(long div, long div2){
        if(div2 == 0) {
            return div;
        }
        return gcd(div2,div%div2);


    }
}