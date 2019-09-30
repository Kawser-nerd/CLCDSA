import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        int ans = 0;
        for(int i=0; i<str.length(); i++) {
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                ans = ans * 10 + Integer.parseInt(str.substring(i, i+1));
            }
        }

        System.out.println(ans);

        in.close();
    }
}