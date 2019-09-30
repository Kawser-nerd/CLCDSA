import java.util.Scanner;

class Main {
    
    void solve(){
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        int[] a = new int[4];
        for(int i = 0; i < 4; i++){
            a[i] = in.nextInt();
        }
        int t = 0;
        for(int i =0; i < s.length(); i++){
            if(t < 4 && i == a[t]){
                t++;
                System.out.print("\"");
            }
            System.out.print(s.charAt(i));
        }
        if(s.length() == a[3]){
            System.out.print("\"");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
}