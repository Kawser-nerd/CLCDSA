using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
    class Program
    {
      static void Main(string[] args){
        var list = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        Array.Sort(list);
        Console.Write(list[0]*list[1] /2);
      }
    }