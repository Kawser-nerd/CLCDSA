import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int n = 0;
        int w = 0;
        int e = 0;
        int s = 0;
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);

            if( c == 'W')  {
                w++;
            } else if( c == 'E' )  {
                e++;
            } else if( c == 'N' ) {
                n++;
            } else {
                s++;
            }
        }

        boolean ns = n == 0 && s == 0 || n != 0 && s != 0;
        boolean we = w == 0 && e == 0 || w != 0 && e != 0;
        System.out.println(ns&&we?"Yes":"No");
    }
}