using System;
using System.Collections;
class Program{
  static void Main(){
    string X = Console.ReadLine();
    ArrayList al = new ArrayList();
    for (int i = 0;i < X.Length;i++){
      if (X[i] == 'S')
        al.Add(X[i]);
      if (X[i] == 'T' && al.Count != 0 && (char)al[al.Count - 1] == 'S')
        al.RemoveAt(al.Count - 1);
      else if (X[i] == 'T')
        al.Add(X[i]);
    }
    Console.WriteLine(al.Count);
  }
}