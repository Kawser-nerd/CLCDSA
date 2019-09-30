import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] str = s.split(" ", 0);
        for(int i = 0; i<str.length; i++) {
            System.out.print(str[i].charAt(0));
        }
        System.out.println();
    }
}