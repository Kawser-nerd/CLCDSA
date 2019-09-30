import java.util.*;


/**
 * Created by takaesumizuki on 2017/06/14.
 */
public class Main {
    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n + 1];
        int h = 0;
        for (int i = 0; i < n + 1; i++) arr[i] = i;

        for (int i = 0; i < m; i++) {
            //?????
            int c = sc.nextInt();
            int key = 0;
            for(int j = 1; j < arr.length; j++){
                if(arr[j] == c) {
                    key = j;
                    int tmp = h;
                    h = arr[key];
                    arr[key] = tmp;
                    break;
                }
            }
//            int tmp = h;
//            h = arr[key];
//            arr[key] = tmp;
//            for (int j = 0; j < arr.length ; j++) System.out.print(arr[j]);
//            System.out.println("h = " + h);
        }
        for (int i = 1; i < arr.length ; i++) System.out.println(arr[i]);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}