import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        if(a.equals("abc") || a.equals("acb")||a.equals("bac") || a.equals("bca") ||a.equals("cab") ||a.equals("cba")) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}