import java.util.Scanner;

public class Main {
    static final String[] t = {"dream", "dreamer", "erase", "eraser"};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        boolean flag = true;
        int i = s.length() - 1;

        while (i >= 0){
            for (int j = 0; j < 4; j++) {
                flag = true;
                for (int k = 0 ; k <t[j].length() ; k++) {
                    if (i-k < 0 || s.charAt(i-k)!=t[j].charAt(t[j].length() - 1 - k)){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    i -= t[j].length();
                    break;
                }
            }
            if (!flag) break;
        }

        System.out.println(((flag)?"YES":"NO"));
    }
}