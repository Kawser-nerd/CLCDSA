using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Globalization;
using static System.Console;
using static System.Math;
using static Input;

class maki {
    static void Main(string[] args) {
      int n=NextInt(),a=NextInt(),b=NextInt();
      bool ans=true;
      while(ans==true || ans==false){
        if(ans==true){
            if(n<=a){
                WriteLine("Ant");
                return;
            }
            else{
                n-=a;
                ans=false;
            }
        }
        else{
            if(n<=b){
                WriteLine("Bug");
                return;
            }
            else{
                n-=b;
                ans=true;
            }
        }
      } 

    }
}

public class Input
{
    private static Queue<string> queue = new Queue<string>();
    private static void Confirm() { if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(queue.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(queue.Dequeue()); }
    public static string NextString() { Confirm(); return queue.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(queue.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}