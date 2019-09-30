import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] t = new int[4];
        for(int i = 0; i<N; i++) {
            t[i] = sc.nextInt();
        }
        for(int i = N; i<4; i++) {
            t[i] = 0;
        }
        int min = Integer.MAX_VALUE;
        int result = 0;
        for(int i = 0; i<2; i++) {
            int[] niku = {0,0};
            niku[i] += t[0];
            for(int j = 0; j<2; j++) {
                niku[j] += t[1];
                for(int k = 0; k<2; k++) {
                    niku[k] += t[2];
                    for(int l = 0; l<2; l++) {
                        niku[l] += t[3];
                        //                      System.out.println(niku[0] + " " + niku[1]);
                        if(min > Math.abs(niku[0]-niku[1])) {
                            min = Math.abs(niku[0]-niku[1]);
                            result = Math.max(niku[0], niku[1]);
                        }
                        niku[l] -= t[3];
                    }
                    niku[k] -= t[2];
                }
                niku[j] -= t[1];
            }
            niku[i] -= t[0];
        }
        System.out.println(result);
    }
}