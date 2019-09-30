import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = {-1,0,2,0,1,0,1,0,0,1,0,1,0};
        int x = sc.nextInt();
        int y = sc.nextInt();
        if(a[x]==a[y]) {
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}