import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int cnt = 0;
        int pre = 0;
        while(N>0) {
            if(N%10==pre) cnt++;
            else cnt=1;
            if(cnt==3) {
                System.out.println("Yes");
                return;
            }
            pre = N%10;
            N/=10;
        }

        System.out.println("No");
    }
}