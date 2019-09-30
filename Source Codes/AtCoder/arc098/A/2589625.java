import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] c = sc.next().toCharArray();

        int[] west = new int[n];
        int[] east = new int[n];

        if(c[0] == 'W') {
            west[0] = 1;
        } else {
            east[0] = 1;
        }
        for(int i=1; i<n; i++) {
            if(c[i] == 'W') {
                west[i] = west[i-1] + 1;
                east[i] = east[i-1];
            } else {
                west[i] = west[i-1];
                east[i] = east[i-1] + 1;
            }
        }

        int res = east[n-1] + east[0];
        for(int i=1; i<n; i++) {
            int t = east[n-1]-east[i] + west[i-1];
            res = Math.min(t, res);
        }
        System.out.println(res);
    }

}