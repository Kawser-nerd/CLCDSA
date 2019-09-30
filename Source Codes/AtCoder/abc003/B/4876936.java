import java.util.Arrays;
import java.util.Collection;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        String special="atcoder@";
        Boolean S_At;
        Boolean T_At;

        if(S.equals(T)){
            win();
        }

        if(!(S.contains("@")||T.contains("@"))){
            lose();
        }


        for (int i = 0; i < S.length(); i++) {
            S_At = (S.charAt(i) == '@');
            T_At = (T.charAt(i) == '@');


            if (S_At || T_At) {
                if (S_At) {
                    if(!special.contains(T.substring(i, i + 1))){
                        lose();
                    }
                } else if (T_At) {
                    if(!special.contains(S.substring(i, i + 1))){
                        lose();
                    }
                }
            }else if(!(S.charAt(i)==T.charAt(i))){
                lose();
            }
        }
        win();
    }

    static void lose(){
        System.out.println("You will lose");
        System.exit(0);

    }
    static void win(){
        System.out.println("You can win");
        System.exit(0);

    }
    static String adjustValue(int value) {
        if (10 > value) {
            return "0" + value;
        } else {
            return value + "";
        }
    }
}