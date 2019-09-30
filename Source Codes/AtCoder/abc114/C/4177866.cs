using System;
using System.Linq;
using  System.Collections.Generic;
class Program
{
static void Main(string[] args){
var t = new int[]{3,5,7};
var d = long.Parse(Console.ReadLine());
var c = d.ToString().ToCharArray();
Func<long, int> tfs = null;
        tfs = n => (n>d)?0:t.Sum(i=> tfs(n *10+i))+(t.All(i=> n.ToString().Contains(((char)('0'+i)).ToString()))?1:0);
Console.WriteLine(tfs(0));
}
}