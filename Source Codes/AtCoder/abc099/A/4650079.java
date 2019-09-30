import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n<1000) {
            System.out.println("ABC");
            return;
        }
        n = n%1000+1;
        System.out.println("ABD");
    }
}