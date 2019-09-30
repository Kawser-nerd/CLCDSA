import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int max = 0;
        for(int i = 0; i <= a; i++) {
            int temp = a-i;
            max = Math.max(max,i*temp);
        }
        System.out.println(max);
    }
}