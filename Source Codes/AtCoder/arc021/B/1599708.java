import java.util.*;

public class Main {
    private static int L;
    private static int b[];
    private static int a[];

    public static void input(){
        Scanner scan = new Scanner(System.in);

        L = scan.nextInt();
        b = new int[L];
        a = new int[L];

        for (int i=0;i<L;i++){
            b[i] = scan.nextInt();
        }
    }

    public static void main(String args[]) {
        //??
        input();

        boolean flag = true;
        int xor = b[0] ^ b[1];
        for (int i=2;i<L-1;i++){
            xor = xor ^ b[i];
        }
        if (L == 2 && b[0] != b[1]) {
            System.out.println(-1);
            flag = false;
        }
        if (L != 2 && b[L-1] != xor) {
            System.out.println(-1);
            flag = false;
        }

        if (flag){
            a[0] = 0;
            System.out.println(a[0]);
            for (int i=1;i<L;i++){
                a[i] = a[i-1] ^ b[i-1];
                System.out.println(a[i]);
            }
        }
    }
}