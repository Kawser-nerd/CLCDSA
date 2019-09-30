import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class Main {
    static boolean check(int a,int b,int mid){
        if(a <= mid && b <= mid || a > mid && b > mid)return true;
        return false;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int array[] = new int[2 * n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < 2 * n; i++)
            array[i] = Integer.parseInt(st.nextToken());
        array[0] = array[2 * n] = -1;
        int infinity = (int) 1E9 + 5;
        int low = 1;
        int high = 2 * n;
        TreeSet<Integer> zero;
        TreeSet<Integer> ones;
        while (low < high) {
            int mid = (low + high) / 2;
            int temp = -1;
            zero = new TreeSet<>();
            ones = new TreeSet<>();
            ones.add(infinity);
            ones.add(-infinity);
            zero.add(infinity);
            zero.add(-infinity);
            for (int i = 1; i < 2 * n; i++) {
                if (check(array[i],array[i - 1],mid) && i != 1) {
                    //System.out.println(array[i] + " " + mid + " " + i);
                    if (array[i] > mid) ones.add(i);
                    else zero.add(i);
                }
                if (check(array[i],array[i + 1],mid) && i != 2*n - 1) {
                    //System.out.println(array[i] + " " + mid + " " + i);
                    if (array[i] > mid) ones.add(i);
                    else zero.add(i);
                }
            }
            if (zero.size() == 2 && ones.size() == 2) {
                if ((n - 1) % 2 == 0) temp = (array[n] > mid) ? 1 : 0;
                else temp = (array[n] > mid) ? 0 : 1;
            } else {
                int beforezero = zero.floor(n);
                int afterzero = zero.ceiling(n);
                int beforeone = ones.floor(n);
                int afterone = ones.ceiling(n);
                int beforemax = Math.max(beforeone, beforezero);
                int aftermin = Math.min(afterone, afterzero);
                int min = Math.min(aftermin - n, n - beforemax);
                //System.out.println("1 " + aftermin + " " + beforemax + " " + min + " " + beforezero + " " + afterzero + " " + beforeone + " " + afterone);
                if (min == aftermin - n) {
                    if (afterone < afterzero) temp = 1;
                    else temp = 0;
                }
                if (min == n - beforemax) {
                    if (beforeone < beforezero) temp = 0;
                    else temp = 1;
                }
            }
            //System.out.println(mid + " " + low + " " + high + " " + zero + " " + ones + " " + temp);
            if (temp == 1) low = mid + 1;
            else high = mid;
        }
        System.out.println(low);
    }
}