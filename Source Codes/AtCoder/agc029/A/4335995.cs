using System;
using System.Linq;
namespace AtCoderTemplate
{public class App{public static void Main(string[] args)=>Console.WriteLine(Console.ReadLine().ToCharArray().Select((chars,index)=>new{chars,index}).Where(v=>v.chars=='W').Select((v,toPos)=>new{v.index,toPos}).Sum(v=>(long)(v.index-v.toPos)));}}