using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static int med3(int x, int y, int z){
    if(x<y){
      if(y<z) return y; else if(z<x) return x; else return z;
    }else{
      if(z<y) return y; else if(x<z) return x; else return z;
    }
  }
  public static void sort(ref int[] a, int l, int r){
    if(l<r){
      int i=l, j=r;
      int y = i+(j-i)/2;
      if(y%2==0) y--;
      int t1, t2, p=med3(a[i], a[y], a[j]);
      while(true){
        while(a[i]<p) i+=2;
        while(p<a[j]) j-=2;
        if(i>=j) break;
        t1 = a[i-1]; t2 = a[i];
        a[i-1] = a[j-1]; a[i] = a[j];
        a[j-1] = t1; a[j] = t2;
        i+=2; j-=2;
      }
      sort(ref a, l, i-2);
      sort(ref a, j+2, r);
    }
  }
  public static void Main(){
    var nm = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    var a = new int[2*nm[1]];
    for(var i=0; i<nm[1]; i++){
      var ab = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
      a[2*i] = ab[0];
      a[2*i+1] = ab[1];
    }
    sort(ref a, 1, 2*nm[1]-1);
    //for(var i=0; i<nm[1]; i++)Console.WriteLine("[{0} {1}]", a[2*i], a[2*i+1]);
    var c=0;
    var b=0;
    for(var i=0; i<nm[1]; i++){
      if(b<a[2*i]){ b=a[2*i+1]-1; c++; }
    }
    Console.WriteLine(c.ToString());
  }
}