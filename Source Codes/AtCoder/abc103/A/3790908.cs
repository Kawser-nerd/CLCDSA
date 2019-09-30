using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    
    int b = int.Parse(str[1]);
    int c = int.Parse(str[2]);
    int ab = System.Math.Abs(a-b);
    int bc = System.Math.Abs(b-c);
    int ac = System.Math.Abs(a-c);
    int kara =0;
    if (ab<ac){
        kara =ab;
        ab = ac ;
        ac = kara;
        }
    if(ab<bc){
        kara  = ab;
        ab = bc;
        bc= kara ;
    }
    Console.WriteLine(bc + ac);
  }
}