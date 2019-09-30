import java.util.Scanner;

public class Main {
    static int[][] map;
    static int[][] label;

    static int M;
    static int N;
    static int T;
    static int P;
    static int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.nextLine();

        int ans = 9999;
        for (int i = 0; i < 26; i++) {
            String ss = s;
            String temps = "";
            int cnt = 0;
            while(true){
                int ok = 0;
                for (int j = 0; j < ss.length(); j++) {
                    if(ss.charAt(j) != 'a' + i)break;
                    ok++;
                }

                if(ok == ss.length())break;
                cnt++;
                for (int j = 0; j < ss.length() - 1; j++) {
                    if(ss.charAt(j) == 'a' + i || ss.charAt(j + 1) == 'a' + i){
                        temps = temps + (char)('a' + i);
                    }else{
                        temps = temps + '0';
                    }
                }
//                System.out.println(temps);
                ss = temps;
                temps = "";
//                break;

            }
            ans = Math.min(ans, cnt);
        }

        System.out.println(ans);


    }



}