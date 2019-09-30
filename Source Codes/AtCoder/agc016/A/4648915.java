import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        //s??????????????????????????0
        char[] sa = s.toCharArray();
        int count = 100000000;
        boolean sameFlg = true;
        for (int i = 0 ; i < s.length() - 1 ; i++) {
            if (sa[i] != sa[i+1]) {
                sameFlg = false;
            }
        }
        if (sameFlg) {
            count = 0;
        }

        char[][] c = new char[100][s.length()];
        for (int i = 0 ; i < 100 ; i++) {
            for (int j = 0 ; j < s.length(); j++) {
                c[i][j] = ' ';
            }
        }
        for (int j = 0; j < s.length() ; j++) {
            c[0][j] = s.charAt(j);
        }


        for (char ch = 'a' ; ch <= 'z' ; ch++) {
            for (int i = 1 ; i < 100 ; i++) {
                for (int j = 0 ; j < s.length() - 1; j++) {
                    if (c[i - 1][j] == ch || c[i - 1][j + 1] == ch) {
                        c[i][j] = ch;
                    } else {
                        c[i][j] = c[i - 1][j + 1];
                    }
                }
                //??ch?blank????break??????
                boolean flg = true;
                for (int j = 0 ; j < s.length() ; j++) {
                    if (c[i][j] != ch && c[i][j] != ' ') {
                        flg = false;
                    }
                }
                if (flg) {
                    count = Math.min(count, i);
                    break;
                }
            }

        }

        System.out.println(count);

    }

}