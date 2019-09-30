import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int Y = scan.nextInt();

        for(int i = 0; i<= N; i++){
            for(int j = 0; j<= N-i; j++){
                if(10000*i + 5000*j + 1000*(N-i-j) == Y){

                    System.out.println(i);
                    System.out.println(j);
                    System.out.println(N-i-j);
                    return;
                }
            }
        }

        System.out.println(-1);
        System.out.println(-1);
        System.out.println(-1);

    }
}