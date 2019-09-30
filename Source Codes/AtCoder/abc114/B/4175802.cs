using System;
using System.Linq;
class Program
{
static void Main(string[] args){
var d = Console.ReadLine().ToCharArray().Select<char,int>(c => c-'0').ToArray();
Console.WriteLine(d.Skip(2).Select((int v,int ind) => Math.Abs(753-(d[ind]*100+d[ind+1]*10+d[ind+2]))).Min());
}
}