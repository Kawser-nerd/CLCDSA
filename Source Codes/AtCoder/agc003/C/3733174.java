import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();

        if(n == 1){
            System.out.println(0);
            return;
        }else if(n == 2){
            if(a[0] > a[1]){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
            return;
        }

        int[] a1, a2;
        if(n % 2 == 0){
            a1 = new int[n/2];
            a2 = new int[n/2];
        }else{
            a1 = new int[n/2+1];
            a2 = new int[n/2];
        }
        for(int i=0; i<a1.length; i++){
            a1[i] = a[i*2];
        }
        for(int i=0; i<a2.length; i++){
            a2[i] = a[i*2+1];
        }

        Arrays.sort(a);
        long ans = 0;
        for(int i=0; i<a1.length; i++){
            int pos = Arrays.binarySearch(a, a1[i]);
            if(pos % 2 == 1) ans++;
        }

        // for(int i=0; i<n; i++){
        //     if(i % 2 == 0){
        //         a[i] = a1[i/2];
        //     }else{
        //         a[i] = a2[i/2];
        //     }
        // }

        // int pos1 = 0;
        // int pos2 = 0;
        // long ans = 0;
        // for(int i=0; i<n; i++){
        //     if(pos1 >= a1.length || pos2 >= a2.length) break;
        //     if(a1[pos1] > a2[pos2]){
        //         ans += (long)Math.max(0, pos2-pos1+1);
        //         pos2++;
        //     }else if(a1[pos1] < a2[pos2]){
        //         ans += (long)Math.max(0, pos1-pos2);
        //         pos1++;
        //     }else{
        //         if(pos1 <= pos2){
        //             pos1++;
        //         }else{
        //             pos2++;
        //         }
        //     }
        // }

        System.out.println(ans);
    }
}