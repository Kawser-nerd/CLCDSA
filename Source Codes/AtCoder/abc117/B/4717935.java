import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[101];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int count = 0;
        for(int i = 0; i < 100; i ++) {
            count += arr[i];
        }
        if(arr[100] < count) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}