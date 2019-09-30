using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program {

    static void Main(string[] args) {
        //System.IO.FileInfo o2 = new System.IO.FileInfo("c:\\out555.txt");
        //var w = o2.CreateText();
        //w.WriteLine("abc");

        //string s = Console.ReadLine();
        //bool bManual = s.StartsWith("m");
        //if (bManual) s = s.Substring(1);
        //int N = int.Parse(s);
        //for (int i = 0; i < N; i++) {
        //    var o2 = new ShoppingPlan();
        //    string[] s2 = Console.ReadLine().Split(' ');
        //    int A = int.Parse(s2[0]);
        //    int B = int.Parse(s2[1]);
        //    int F = int.Parse(s2[2]);
        //    string[] items = Console.ReadLine().Split(' ');
        //    string[] stores = new string[B];
        //    for (int j = 0; j < B; j++) {
        //        stores[j] = Console.ReadLine();
        //    }
        //    string s3=o2.Process2(items, stores, F);
        //    Console.WriteLine("Case #{0}: {1}", i + 1, s3);

        //}


        //string s = Console.ReadLine();
        //bool bManual = s.StartsWith("m");
        //if (bManual) s = s.Substring(1);
        //int N = int.Parse(s);
        //for (int i = 0; i < N; i++) {

        //    // Replace these lines only.
        //    var o = new EggDrop();
        //    bool MultiLine = false;

        //    if (MultiLine) {
        //        string[] sOut = o.ProcessMulti(Console.ReadLine());
        //        Console.WriteLine("Case #{0}:", i + 1);
        //        for (int j = 0; j < sOut.Length; j++) {
        //            Console.WriteLine(sOut[j]);
        //        }

        //    } else {
        //        string sOut = o.Process(Console.ReadLine());
        //        Console.WriteLine("Case #{0}: {1}", i + 1, sOut);
        //    }

        //}

        string s = Console.ReadLine();
        bool bManual = s.StartsWith("m");
        if (bManual) s = s.Substring(1);
        int N = int.Parse(s);
        for (int i = 0; i < N; i++) {

                var o2 = new SavingTheUniverse();
                string s2 = Console.ReadLine();
                string[] engines = new string[int.Parse(s2)];
                for (int j = 0; j < engines.Length; j++) {
                    engines[j] = Console.ReadLine();
                }
                s2 = Console.ReadLine();
                string[] queries = new string[int.Parse(s2)];
                for (int j = 0; j < queries.Length; j++) {
                    queries[j] = Console.ReadLine();
                }
                string s3=o2.Process2(engines,queries);
                Console.WriteLine("Case #{0}: {1}", i + 1, s3);
        }

        if (bManual) Console.ReadKey();
    }
}
