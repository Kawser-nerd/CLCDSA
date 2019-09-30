import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 0;
        for(int i = 0; i<12; i++) {
            String s = sc.next();
            if(s.contains("r")) c++;
        }
        System.out.println(c);
    }
}