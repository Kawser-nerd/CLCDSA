using System;
public class P{
public static void Main(){
    int c=0;
    for(int i=0;i<12;i++)c+=(System.Text.RegularExpressions.Regex.IsMatch(Console.ReadLine(),"r")?1:0);
Console.WriteLine(c);
}
}