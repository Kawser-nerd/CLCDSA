import java.util.Scanner;

class Main {
    
    void solve(){
        Scanner in = new Scanner(System.in);
        String[] list = in.nextLine().split(" ");
        String a = list[0];
        String b = list[1];
        int max = Integer.MIN_VALUE;

        int v = Integer.valueOf("9" + a.charAt(1) + a.charAt(2));
        max = Math.max(max, v - Integer.valueOf(b));
        
        v = Integer.valueOf(a.charAt(0) + "9" + a.charAt(2));
        max = Math.max(max, v - Integer.valueOf(b));
        
        v = Integer.valueOf("" + a.charAt(0) + a.charAt(1) + "9");
        max = Math.max(max, v - Integer.valueOf(b));
        
        v = Integer.valueOf("1" + b.charAt(1) + b.charAt(2));
        max = Math.max(max, Integer.valueOf(a) - v);
        
        v = Integer.valueOf(b.charAt(0) + "0" + b.charAt(2));
        max = Math.max(max, Integer.valueOf(a) - v);
        
        v = Integer.valueOf("" + b.charAt(0) + b.charAt(1) + "0");
        max = Math.max(max, Integer.valueOf(a) - v);
        
        System.out.println(max);
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
}