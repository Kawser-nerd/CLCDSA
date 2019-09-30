using System;
public class P{
public static void Main(){
int a=int.Parse(Console.ReadLine());
if(a%2==0){Console.WriteLine(-1);return;}
int c=(a-1)/2;
char[]s=Console.ReadLine().ToCharArray();
for(int i=0;i<=c;i++){
if(s[c-i]!=(i%3==0?'b': i%3==1?'a':'c')){Console.WriteLine(-1);return;}
if(s[c+i]!=(i%3==0?'b': i%3==1?'c':'a')){Console.WriteLine(-1);return;}
}
Console.WriteLine(c);
}
}