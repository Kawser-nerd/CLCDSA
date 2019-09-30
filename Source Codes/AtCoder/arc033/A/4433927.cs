using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading.Tasks;


class maki {
    static void Main(string[] args) {
        //int[] cin=Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        //string s=Console.ReadLine();
        Console.WriteLine(n*(n+1)/2);
    }
}