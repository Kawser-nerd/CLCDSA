import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            char[] t = s.toCharArray();
            int ansA = -1;
            int ansB = -1;

            for (int i = 0; i < t.length; i++) {
                if ( i < t.length - 1 ) {
                    if ( t[i] == t[i + 1] ) {
                        ansA = i + 1;
                        ansB = i + 2;
                    }
                }
                if ( i < t.length - 2 ) {
                    if ( t[i] == t[i + 1] || t[i] == t[i + 2] || t[i + 1] == t[i + 2] ) {
                        ansA = i + 1;
                        ansB = i + 3;
                    }
                }
            }
            System.out.println(ansA + " " + ansB);
        }
    }
}