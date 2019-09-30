import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        boolean flag = false;
        int i = s.length - t.length;
        for(i = s.length - t.length; i >= 0; i--) {
            flag = true;
            for(int j = 0; j < t.length; j++) {
                if(!(s[i + j] == '?' || s[i + j] == t[j])) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) {
            for(int j = 0; j < s.length; j++) {
                if(s[j] == '?') {
                    if(i <= j && j < i + t.length) s[j] = t[j - i];
                    else s[j] = 'a';
                }
            }
            System.out.println(String.valueOf(s));
        }else {
            System.out.println("UNRESTORABLE");
        }

        sc.close();
    }
}