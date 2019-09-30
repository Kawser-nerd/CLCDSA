import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(a-b>=0) {
            System.out.println("delicious");
        }else if(a-b>=-x) {
            System.out.println("safe");
        }else {
            System.out.println("dangerous");
        }
    }
}