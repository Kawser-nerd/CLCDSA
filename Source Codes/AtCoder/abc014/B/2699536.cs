using System;
class Program{
    static void Main(string[] args){
        int[] s1=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int[] s2=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int a=0;
        
        for(int i=0;i<21;i++){
            if ((s1[1]&(1<<i))!=0) { a +=s2[i]; }
        }
        
        Console.WriteLine(a);
    }
}