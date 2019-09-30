import java.util.*;
public class NN {
    static Scanner sc = new Scanner(System.in);
    static int k; 
    {
/*        for (int r=1; r<=25; r++)
            for (int c=1; r*c<=25; c++)
            for (int n=0; n<=r*c; n++) {
            int a = val(r, c, n);
            int b = val2(r, c, n);
            if (a != b){
            System.out.print(r+" "+c+" "+n+" "+a+" "+b);
System.out.print("!!!!!");
            System.out.println();
            }
        }
        System.out.println("foo");*/
        k = sc.nextInt();
        for (int kk=1; kk<=k; kk++) {
            System.out.print("Case #"+kk+": ");
            int r = sc.nextInt();
            int c = sc.nextInt();
            int n = sc.nextInt();
            int a = val(r, c, n);
//            int b = val2(r, c, n);
            System.out.println(val(r, c, n));
/*            System.out.print(r+" "+c+" "+n+" "+a+" "+b);
            if (a != b) System.out.print("!!!");
            System.out.println();*/
        }
    }
    
/*    static int val2(int r, int c, int n) {
        int N = 1<<(r*c);
        int result = r*c*8;
        for (int s=0; s<N; s++) {
            if (Integer.bitCount(s) != n) continue;
            boolean g[][] = new boolean[r][c];
            int seed = s;
            for (int i=0; i<r; i++)
                for (int j=0; j<c; j++) {
                g[i][j] = (seed%2)==1;
                seed>>=1;
            }
            int val = 0;
            for (int i=0; i<r; i++) for (int j=0; j<c-1; j++)
                if (g[i][j] && g[i][j+1]) val++;
            for (int i=0; i<r-1; i++) for (int j=0; j<c; j++)
                if (g[i][j] && g[i+1][j]) val++;
            result = Math.min(result, val);
        }
        return result;
    }*/
    
    static int thing(int r, int c, int n, int basegood, int corn, int edg) {
        if (n<=basegood)
            return 0;
        n -= basegood;
        if (n<=corn)
            return 2*n;
        int result=2*corn;
        n-=corn;
        if (n<=edg)
            return result+3*n;
        result += 3*edg;
        n -= edg;
        return result + 4*n;
    }
    
    static int special(int size, int n) {
        if (size%2==0) {
            if (n <= size/2) return 0;
            return 2*(n-size/2)-1;
        }
        else {
            if (n <= size/2+1) return 0;
            return 2*(n-size/2-1);
        }
    }
    
    static int val(int r, int c, int n) {
        if (r==1)
            return special(c, n);
        if (c==1)
            return special(r, n);
        if ((r*c) % 2 == 0) 
            return thing(r, c, n, r*c/2, 2, r+c-4);
        else 
            return Math.min(thing(r, c, n, r*c/2+1, 0, r+c-2),
                            thing(r, c, n, r*c/2, 4, r+c-6));
    }
    
    public static void main(String[] args) {
        new NN();
    }
}