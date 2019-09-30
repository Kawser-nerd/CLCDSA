import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;
        int E = 0;
        int F = 0;
        for (int i = 0; i < S.length(); i++) {
            char set = S.charAt(i);
            switch (set) {
            case 'A':
                A++;
                continue;
            case 'B':
                B++;
                continue;
            case 'C':
                C++;
                continue;
            case 'D':
                D++;
                continue;
            case 'E':
                E++;
                continue;
            case 'F':
                F++;
                continue;
            }
        }
        System.out.println(A + " " + B + " " + C + " " + D + " " + E + " " + F);
    }
}