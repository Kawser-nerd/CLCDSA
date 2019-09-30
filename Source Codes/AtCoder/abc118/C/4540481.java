import java.util.*;

public class Main 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        logic(sc);
    }
    
    public static void logic(Scanner sc)
    {
        int ans = 0;
        
        int m = sc.nextInt();
        ans = gcd(sc.nextInt(),sc.nextInt());
        for(int i=1;i<=m-2;i++)
        {
            ans = gcd(ans,sc.nextInt());
        }
        
        sc.close();
        System.out.print(ans);
    }

    private static int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    } 
}