using System;
class Program{
    static void Main(string[] args){
        string[] str = Console.ReadLine().Split(' ');
        int h = int.Parse(str[0].ToString());
        int w = int.Parse(str[1].ToString());
        string[] c = new string[h];
        for(int i=0;i<h;i++){
            c[i] = Console.ReadLine();
        }
        for(int i=0;i<h;i++){
            Console.WriteLine(c[i]);
            Console.WriteLine(c[i]);
        }
    }
}