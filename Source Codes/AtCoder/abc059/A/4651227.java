import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char a = sc.next().charAt(0);
        char b = sc.next().charAt(0);
        char c = sc.next().charAt(0);
        System.out.println((char)(a-'a'+'A') +""+ (char)(b-'a'+'A') +""+ (char)(c-'a'+'A'));
    }
}