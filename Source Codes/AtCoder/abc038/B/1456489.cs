using System;

public class Program{
    public static void Main(){
        string[] s=Console.ReadLine().Split();
        int T1=int.Parse(s[0]);
        int T2=int.Parse(s[1]);
        string[] ss=Console.ReadLine().Split();
        int TT1=int.Parse(ss[0]);
        int TT2=int.Parse(ss[1]);
        if(T1==TT1||T1==TT2||T2==TT1||T2==TT2){
            Console.WriteLine("YES");
        }else{
            Console.WriteLine("NO");
        }
    }
}