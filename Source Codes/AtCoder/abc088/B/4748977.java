import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int a[] = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(sc.next());
        }

        Sort(a);

        int alice = 0;
        int bob = 0;

        for (int i = 0; i < n; i++) {
            if(i % 2 == 0){
                alice += a[i];
            }else{
                bob += a[i];
            }
        }

        System.out.println(alice - bob);

        sc.close();
    }

    static void Sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = array.length - 1; j > i; j--) {
                if (array[i] < array[j]) {
                    int tem = array[i];
                    array[i] = array[j];
                    array[j] = tem;
                }
            }
        }
    }
}