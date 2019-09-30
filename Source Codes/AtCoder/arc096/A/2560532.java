import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int sum = 0;
        int max_xy = Max(x,y);
        int min_xy = Min(x,y);
        int max_ab = Max(a,b);
        int max_num, min_num;
        if(max_xy == x){ max_num = a; min_num = b; }
        else           { max_num = b; min_num = a; }

        if( c*2 >= a+b ){
            sum = a*x + b*y;
        }
        if( c*2 < a+b ){
            if( c*2 >= max_num){
                sum = max_num * Math.abs(x-y) + 2 * min_xy * c;
            }
            else{
                sum = 2 * max_xy * c;
            }
        }
        /*if( c <= min){
            sum = c * Max(x,y) * 2;
        }*/
        System.out.println(sum);
    }
    public static int Max (int p, int q){
        int res;
        if( p >= q ) res = p;
        else         res = q;
        return(res);
    }
    public static int Min (int p, int q){
        int res;
        if( p <= q ) res = p;
        else         res = q;
        return(res);
    }
}