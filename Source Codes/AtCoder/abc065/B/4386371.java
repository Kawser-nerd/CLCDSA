import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i = 0; i < N; i++) a[i] = sc.nextInt();

        int button = 0;
        int count = 1;
        while(a[button] != 2){
            button = a[button] - 1;
            count++;
            if(count > N) break;
        }
        System.out.println( count < N ? count : -1);
    }
}