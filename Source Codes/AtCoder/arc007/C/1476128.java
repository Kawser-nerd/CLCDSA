import java.util.Scanner;
 
class Main{
    static boolean[] al;
    static int[] c;
    static int[] t;
    static int n;
 
    static int search(){
        boolean f = true;
        for(int i = 0;i < n;i++)
            f = (f && t[i] > 0);
        if(f)
            return 0;
 
        int min = n;
        for(int i = 0;i < n;i++){
            if(!al[i]){
                al[i] = true;
                for(int j = 0;j < n;j++)
                    t[j] += (c[(j + i) % n] > 0) ? 1 : 0;
                min = Math.min(min,search() + 1);
                for(int j = 0;j < n;j++)
                    t[j] -= (c[(j + i) % n] > 0) ? 1 : 0;
                al[i] = false;
            }
        }
        return min;
    }
 
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
 
        String cin = scan.next();
 
        n = cin.length();
 
        c = new int[n];
        t = new int[n];
        al = new boolean[n]; 
        for(int i = 0;i < n;i++){
            c[i] = t[i] = (cin.charAt(i) == 'o') ? 1:0;
            al[i] = false;
        }

        al[0] = true;
 
        System.out.println(search() + 1);
            
    }
}